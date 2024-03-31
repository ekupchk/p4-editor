#ifndef LIST_HPP
#define LIST_HPP
/* List.hpp
 *
 * doubly-linked, double-ended list with Iterator interface
 * EECS 280 Project 4
 */

#include <iostream>
#include <iterator> //std::bidirectional_iterator_tag
#include <cassert>  //assert

using namespace std;

template <typename T>
class List {
public:

  /*STATUS: 
    Should be fine, untested.
  */
  //EFFECTS:  returns true if the list is empty
  bool empty() const{
    return first == nullptr;
  }

  /*STATUS: 
    Should be fine, untested.
    If errors occur, it's from indexing issues.
  */
  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow. Instead, keep track of the size
  //         with a private member variable. That's how std::list does it.
  int size() const{
    return ListSize;
  }

  /*STATUS: 
    Should be fine, untested.
    If errors occur, its from indexing issues.
  */
  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  T & front(){
    return first->datum;
  }

  /*STATUS: 
    Should be fine, untested.
    If errors occur, its from indexing issues.
  */
  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back(){
    return last->datum;
  }

  /*STATUS: 
    
  */
  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum){
    //Creating the new front node
    //Works for all cases
    Node *new_front_node = new Node();
    new_front_node->datum = datum;
    new_front_node->prev = nullptr;
    new_front_node->next = first;
    
    //If the first node is nullptr, then is an empty list
    //Make both the first and last nodes this new node
    if(first == nullptr){
      last = new_front_node;
    }else{ //At least one element in the list
      first->prev = new_front_node;
    }
    first = new_front_node;
    ListSize++;
  };

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum){
    Node *new_end_node = new Node();
    new_end_node->datum = datum;
    new_end_node->next = nullptr;
    new_end_node->prev = last;

    //If the first node is nullptr, then is an empty list
    //Make both the first and last nodes this new node
    if(first == nullptr){
      first = new_end_node;
    }else{ //At least one element in the list
      last->next = new_end_node;
    }
    last = new_end_node;
    ListSize++;
  };

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front(){
    Node *replaced_front = first;
    if(first == last){
      last = nullptr;
      ListSize = 0;
    }else{
      ListSize--;
    }
    first = first->next;
    delete replaced_front;
  };

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back(){
    Node *replaced_end = last;
    if(first == last){
      first = nullptr;
      ListSize = 0;
    }else{
      ListSize--;
    }
    last = last->prev;
    delete replaced_end;
  };

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear(){
    while(first != last){
      pop_back();
    }
    if(first != nullptr){
      delete first;
      first = nullptr;
      last = nullptr;
    }
  };

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you should omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists.

  List<T>() : ListSize(0), first(nullptr), last(nullptr){};

  ~List<T>(){
    Node* current_element;
    for (List<T>::Iterator item_iterator = begin(); item_iterator != end(); ++item_iterator) {
        cout << *item_iterator << endl;
        current_element = item_iterator.node_ptr;
        delete current_element;
    }
    delete this;
  };


private:
  //a private type
  int ListSize = 0;
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other);

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty

public:
  ////////////////////////////////////////
  class Iterator {
    //OVERVIEW: Iterator interface to List
  public:
    // Add a default constructor here. The default constructor must set both
    // pointer members to null pointers.
    Iterator() : list_ptr(nullptr), node_ptr(nullptr), initialized_via_default(true){}


    // Add custom implementations of the destructor, copy constructor, and
    // overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you should omit them. A user
    // of the class must be able to copy, assign, and destroy Iterators.
    
    //destructor (i dont think much is needed besides a destructor line so it can destruct when done)
    ~Iterator(){}
    
    //copy constructor?
    Iterator(Iterator &copy){
      list_ptr = copy.list_ptr;
      node_ptr = copy.node_ptr;
      initialized_via_default = false;
    }

    //overloaded assignment
    Iterator & operator=(const Iterator &rhs){
      list_ptr = rhs.list_ptr;
      node_ptr = rhs.node_ptr;
      return *this;
    }



    // Your iterator should implement the following public operators:
    // *, ++ (both prefix and postfix), == and !=.
    // Equality comparisons must satisfy the following rules:
    // - two default-constructed iterators must compare equal
    // - a default-constructed iterator must compare unequal to an
    //   iterator obtained from a list, even if it is the end iterator
    // - two iterators to the same location in the same list must
    //   compare equal
    // - two iterators to different locations in the same list must
    //   compare unequal
    // - comparing iterators obtained from different lists results in
    //   undefined behavior
    //   - Your implementation can handle this however you like, but
    //     don't assume any particular behavior in your test cases --
    //     comparing iterators from different lists essentially
    //     violates the REQURES clause.
    // Note: comparing both the list and node pointers should be
    // sufficient to meet these requirements.



  public:
    // Type aliases required to work with STL algorithms. Do not modify these.
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    // This operator will be used to test your code. Do not modify it.
    // REQUIRES: Iterator is either dereferenceable or an end Iterator
    // EFFECTS:  moves this Iterator to point to the previous element
    //           and returns a reference to this Iterator
    Iterator& operator--() { // prefix -- (e.g. --it)
  assert(list_ptr);
  assert(*this != list_ptr->begin());
  if (node_ptr) {
    node_ptr = node_ptr->prev;
  } else { // decrementing an end Iterator moves it to the last element
    node_ptr = list_ptr->last;
  }
  return *this;
}

    // This operator will be used to test your code. Do not modify it.
    // REQUIRES: Iterator is either dereferenceable or an end Iterator
    // EFFECTS:  moves this Iterator to point to the previous element
    //           and returns a copy of the original Iterator
    Iterator operator--(int /*dummy*/) { // postfix -- (e.g. it--)
      Iterator copy = *this;
      operator--();
      return copy;
    }

    Iterator operator++(){
      assert(list_ptr);
      if (node_ptr) {
        node_ptr = node_ptr->next;
      } else { // decrementing an end Iterator moves it to the last element
        node_ptr = list_ptr->first;
      }
      return *this;
    }

    Iterator operator++(int /*dummy*/) { // postfix -- (e.g. it--)
      Iterator copy = *this;
      operator++();
      return copy;
    }
    // REQUIRES: Iterator is dereferenceable
    // EFFECTS: returns the underlying element by pointer
    // NOTE: T must be a class type to use the syntax it->. If T has a
    //       member variable f, then it->f accesses f on the
    //       underlying T element.
    T* operator->() const {
      return &(operator*());
    }

    bool operator==(Iterator rhs){
      if((initialized_via_default == true) || (rhs.initialized_via_default == true)){
        std::cout << "operator == returns " << (initialized_via_default == rhs.initialized_via_default) << std::endl;
        return (initialized_via_default == rhs.initialized_via_default);
      }

      if(list_ptr == rhs.list_ptr){
        std::cout << "operator == returns " << (node_ptr == rhs.node_ptr) << std::endl;
        return (node_ptr == rhs.node_ptr);
      }

      //expects undefined behavior if you compare
      //different lists, so show this way
      std::cout << "operator == returns false by default" << std::endl;
      return false;
    }

    bool operator!=(Iterator rhs){
      bool return_value = !(operator==(rhs));
      std::cout << "operator != returns " << return_value << std::endl;
      return return_value;
    }

    T operator*(){
      return node_ptr->datum;
    }
//hjgdkhadjdui ididhg aidhfgididgg ahdighdg 

  private:
    const List *list_ptr; //pointer to the List associated with this Iterator
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here
    bool initialized_via_default = false;

    // add any friend declarations here
    friend class List;
    //ALSO A PLACE WE NEED TO MAKE THE PRIVATE

    //I think we need this private iterator constructor in order to specify node without list - Elijah
    Iterator(Node *np) : node_ptr(np){}

    // construct an Iterator at a specific position in the given List
    Iterator(const List *lp, Node *np): node_ptr(np), list_ptr(lp){}
      // // int counter = 0;
      // // Node* current_node = lp->begin;
      // // while((counter < ListSize) && (current_node != np)){
      // //   counter++;
      // //   current_node = current_node->next;
      // // }
      // std::cout << "unfinished function Iterator(const List *lp, Node *np) activated" << std::endl;
    // }

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const{
    return Iterator(first);
  }

  // return an Iterator pointing to "past the end"
  Iterator end() const{
    return Iterator(nullptr);
  }

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container.
  //         Returns An iterator pointing to the element that followed the
  //         element erased by the function call
  Iterator erase(Iterator i){
    for(List<int>::Iterator *traverse = i.list_ptr.begin(); traverse != i.list_ptr.end(); traverse++){
      if(traverse->node_ptr == i->node_ptr){
        if(traverse->node_ptr->next == nullptr){
          traverse--;
          traverse->node_ptr->next = nullptr;
          i = traverse;
        }
        else{
          traverse--;
          traverse->node_ptr->next = i->node_ptr->next;
          traverse++;
          traverse->node_ptr->prev =i->node_ptr->prev;
          i = traverse;
        }
        break;
      }
      return i;
    }
  }
  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: Inserts datum before the element at the specified position.
  //         Returns an iterator to the the newly inserted element.
  Iterator insert(Iterator i, const T &datum){
    // std::cout << "unfinished function Iterator insert(Iterator i, const T &datum){ activated" << std::endl;
    Node *new_data = *Node(i);
    Iterator new_iterator;
    return new_iterator;
    
  }
};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.


#endif // Do not remove this. Write all your code above this line.
