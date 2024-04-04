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
    void copy_all(const List<T> &other){
      if(other.first != nullptr){
        Node* item_at_index = other.first;
        while(item_at_index != nullptr){
          push_back(item_at_index->datum);
          item_at_index = item_at_index->next;
        }
      }
    }

    Node *first;
    Node *last;

  public:

    //EFFECTS:  returns true if the list is empty
    bool empty() const{
      return first == nullptr;
    }

    //EFFECTS: returns the number of elements in this List
    //HINT:    Traversing a list is really slow. Instead, keep track of the size
    //         with a private member variable. That's how std::list does it.
    int size() const{
      return ListSize;
    }

    //REQUIRES: list is not empty
    //EFFECTS: Returns the first element in the list by reference
    T & front(){
      return first->datum;
    }

    //REQUIRES: list is not empty
    //EFFECTS: Returns the last element in the list by reference
    T & back(){
      if(last != nullptr) { return last->datum; }
      return first->datum;
    }

    //EFFECTS:  inserts datum into the front of the list
    void push_front(const T &datum){
      Node *new_front_node = new Node();
      new_front_node->datum = datum;
      new_front_node->prev = nullptr;
      new_front_node->next = first;

      if(first != nullptr){
        first->prev = new_front_node;
        if(last == nullptr){
          last = first;
        }
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

      if(first != nullptr){
        if(last != nullptr){
          last->next = new_end_node;
          new_end_node->prev = last;
        }else{
          first->next = new_end_node;
          new_end_node->prev = first;
        }
        last = new_end_node;
      }else{
        first = new_end_node;
      }

      ListSize++;
    };

    //REQUIRES: list is not empty
    //MODIFIES: may invalidate list iterators
    //EFFECTS:  removes the item at the front of the list
    void pop_front(){
      Node *replaced_front = first;
      if(last == nullptr){
        first = nullptr;

      }else{
        first = replaced_front->next;
        first->prev = nullptr;
        if(replaced_front->next == last){
          last = nullptr;
        }
      }

      ListSize--;
      delete replaced_front;
    };

    //REQUIRES: list is not empty
    //MODIFIES: may invalidate list iterators
    //EFFECTS:  removes the item at the back of the list
    void pop_back(){
      Node *replaced_end;
      if(last == nullptr){
        replaced_end = first;
        first = nullptr;
      }else{
        replaced_end = last;
        last = replaced_end->prev;
        last->next = nullptr;
        if(last == first){
          last = nullptr;
        }
      }
      ListSize--;
      delete replaced_end;
    };

    //MODIFIES: may invalidate list iterators
    //EFFECTS:  removes all items from the list
    void clear(){
      // while(first != last){
      //   pop_back();
      // }
      // if(first != nullptr){
      //   delete first;
      //   first = nullptr;
      //   last = nullptr;
      // }

      //DUH, this works. 
      //made it too complex before
      while(first){
        pop_back();
      }
    };

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you should omit them. A user
    // of the class must be able to create, copy, assign, and destroy Lists.

    List<T>() : ListSize(0), first(nullptr), last(nullptr){};

    //copy constructor?
    List<T>(List<T> &copy){
      ListSize = 0;
      first = nullptr;
      last = nullptr;

      copy_all(copy);
    }

    //overloaded assignment
    List<T> & operator=(const List<T> &rhs){
      if(this != &rhs){
        clear();
        copy_all(rhs);
      }
      return *this;
    }

    ~List<T>(){
      clear();
    };




    ////////////////////////////////////////
    class Iterator {
        //OVERVIEW: Iterator interface to List
      public:
        Iterator() : list_ptr(nullptr), node_ptr(nullptr){}


        // Add custom implementations of the destructor, copy constructor, and
        // overloaded assignment operator, if appropriate. If these operations
        // will work correctly without defining these, you should omit them. A user
        // of the class must be able to copy, assign, and destroy Iterators.
        
        //copy constructor?
        Iterator(const Iterator &copy){
          list_ptr = copy.list_ptr;
          node_ptr = copy.node_ptr;
        }

        //overloaded assignment
        Iterator & operator=(const Iterator &rhs){
          if(this != &rhs){
            node_ptr = rhs.node_ptr;
            //list_ptr = copy.list_ptr;
          }
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
          } else {
            node_ptr = list_ptr->last;
          }
          return *this;
        }

        // This operator will be used to test your code. Do not modify it.
        // REQUIRES: Iterator is either dereferenceable or an end Iterator
        // EFFECTS:  moves this Iterator to point to the previous element
        //           and returns a copy of the original Iterator
        Iterator operator--(int /*dummy*/) { // postfix -- (e.g. it--)
          Iterator new_version = *this;
          operator--();
          return new_version;
        }

        Iterator operator++(){
          assert(list_ptr);
          if (node_ptr) {
            node_ptr = node_ptr->next;
          } else {
            node_ptr = list_ptr->first;
          }
          return *this;
        }

        Iterator operator++(int /*dummy*/) { // postfix -- (e.g. it--)
          Iterator new_version = *this;
          node_ptr = node_ptr->next;
          return new_version;
        }
        // REQUIRES: Iterator is dereferenceable
        // EFFECTS: returns the underlying element by pointer
        // NOTE: T must be a class type to use the syntax it->. If T has a
        //       member variable f, then it->f accesses f on the
        //       underlying T element.
        T* operator->() const {
          return &(operator*());
        }

        bool operator==(const Iterator rhs) const{
          return (node_ptr == rhs.node_ptr);
        }

        bool operator!=(const Iterator rhs) const{
          return !(operator==(rhs));
        }
        

        T operator*(){
          return node_ptr->datum;
        }

      private:
        const List *list_ptr;
        Node *node_ptr;

        friend class List;

        Iterator(Node *np) : node_ptr(np){}

        // construct an Iterator at a specific position in the given List
        Iterator(const List *lp, Node *np): list_ptr(lp), node_ptr(np){}

        void copy_all(const Iterator &rhs){
          node_ptr = rhs.node_ptr;
        }
    };//List::Iterator

    // return an Iterator pointing to the first element
    Iterator begin() const{
      return Iterator(this, first);
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
      List<int>::Iterator *traverse = i.list_ptr.begin();
      for(; traverse != i.list_ptr.end(); traverse++){
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
      Iterator new_iterator;
      Node *new_data = new Node();
      if(i->node_ptr == first){
        (i->list_ptr).push_front(datum);
        new_iterator = new_iterator(this, first);
        delete new_data;
      }else if(i.node_ptr == last){
        (i->list_ptr).push_back(datum);
        new_iterator = new_iterator(this, first);
        delete new_data;
      }else{
        new_data->datum = datum;
        new_data->prev = (i.node_ptr)->prev;
        new_data->next = (i->node_ptr);
        ((i.node_ptr).prev)->next = new_data;
        (i.node_ptr)->prev = new_data;
        new_iterator = new_iterator(this, new_data);
      }
      
      return new_iterator;
    }
};//List



#endif // Do not remove this. Write all your code above this line.
