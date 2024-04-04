#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

//Empty execution
TEST(testing_empty_default) {
    //Checking consecuitve executions 
    cout << "testing empty default" << endl;
    List<int> emptyList;
    ASSERT_TRUE(emptyList.empty());
    ASSERT_TRUE(emptyList.empty());
    std::cout << "Consecutive test of default empty passed" << std::endl;

    List<int> emptyList2;
    ASSERT_TRUE(emptyList2.empty());
    for (int i = 0; i < 5; ++i) {
        emptyList2.push_back(i);
    }
    ASSERT_FALSE(emptyList2.empty());
    ASSERT_FALSE(emptyList2.empty());
    std::cout << "Test of default empty pre and post filled passed" << std::endl;

    int j = 0;
    for (List<int>::Iterator it = emptyList2.begin(); it != emptyList2.end(); ++it, ++j) {
        std::cout << "At item #" << j << ", get " << *it << std::endl;
        ASSERT_EQUAL(*it, j);
    }

    std::cout << "Test of prefilled list variable modifications passed" << std::endl;
}

//passes
TEST(testing_empty_copy) {
    //Checking consecuitve executions 
    List<int> base_maker;
    List<int> emptyList = base_maker;
    ASSERT_TRUE(emptyList.empty());
    ASSERT_TRUE(emptyList.empty());

    ASSERT_TRUE(base_maker.empty());
    for (int i = 0; i < 5; ++i) {
        base_maker.push_back(i);
    }
    List<int> emptyList2 = base_maker;
    ASSERT_FALSE(emptyList2.empty());
    ASSERT_FALSE(emptyList2.empty());

    int j = 0;
    for (List<int>::Iterator it = emptyList2.begin(); it != emptyList2.end(); ++it, ++j) {
        std::cout << "At item #" << j << ", get " << *it << std::endl;
        ASSERT_EQUAL(*it, j);
    }
}

//Testing size default made
TEST(testing_size) {
    List<int> emptyList;
    ASSERT_EQUAL(emptyList.size(),0);
    ASSERT_EQUAL(emptyList.size(),0);
    //Testing base situation multiple times

    for (int i = 0; i < 5; ++i) {
        emptyList.push_back(i);
    }
    ASSERT_EQUAL(emptyList.size(),5);
    ASSERT_EQUAL(emptyList.size(),5);
    //Testing size after additions multiple times
    //Independent of the method used to add elements

    int j = 0;
    for (List<int>::Iterator it = emptyList.begin(); it != emptyList.end(); ++it, ++j) {
        std::cout << "At item #" << j << ", get " << *it << std::endl;
        ASSERT_EQUAL(*it, j);
    }

    for (int i = 4; i > -1; --i) {
        emptyList.pop_back();
    }
    ASSERT_EQUAL(emptyList.size(),0);
    ASSERT_EQUAL(emptyList.size(),0);
    //Testing size after removals multiple times
    //Independent of the method used to subtract elements 
}

//passes
TEST(testing_front_back){
    List<int> emptyList;
    //Can have duplicates actually!
    //Check one member list independent of method added
    //Check multiple times to ensure no change
    emptyList.push_front(10);
    ASSERT_EQUAL(emptyList.front(), 10);
    ASSERT_EQUAL(emptyList.front(), 10);
    ASSERT_EQUAL(emptyList.back(), 10);
    ASSERT_EQUAL(emptyList.back(), 10);

    emptyList.push_front(7);
    ASSERT_EQUAL(emptyList.front(), 7);
    ASSERT_EQUAL(emptyList.front(), 7);
    ASSERT_EQUAL(emptyList.back(), 10);
    ASSERT_EQUAL(emptyList.back(), 10);

    //duplicate case so no change expected
    emptyList.push_back(7);
    ASSERT_EQUAL(emptyList.front(), 7);
    ASSERT_EQUAL(emptyList.front(), 7);
    ASSERT_EQUAL(emptyList.back(), 7);
    ASSERT_EQUAL(emptyList.back(), 7);

    //Added to end behavior works
    emptyList.push_back(3);
    ASSERT_EQUAL(emptyList.front(), 7);
    ASSERT_EQUAL(emptyList.front(), 7);
    ASSERT_EQUAL(emptyList.back(), 3);
    ASSERT_EQUAL(emptyList.back(), 3);

    //7 10 7 3 is list
    emptyList.pop_back();
    ASSERT_EQUAL(emptyList.front(), 7);
    ASSERT_EQUAL(emptyList.front(), 7);
    ASSERT_EQUAL(emptyList.back(), 7);
    ASSERT_EQUAL(emptyList.back(), 7);

    emptyList.pop_front();
    ASSERT_EQUAL(emptyList.front(), 10);
    ASSERT_EQUAL(emptyList.front(), 10);
    ASSERT_EQUAL(emptyList.back(), 7);
    ASSERT_EQUAL(emptyList.back(), 7);
}
//passes
TEST(testing_push_front_back){
    List<int> emptyList;

    emptyList.push_front(3);
    ASSERT_EQUAL(emptyList.front(), 3);
    ASSERT_EQUAL(emptyList.back(), 3);
    ASSERT_EQUAL(emptyList.size(),1);
    
    emptyList.push_front(2);
    emptyList.push_front(1);
    ASSERT_EQUAL(emptyList.front(), 1);
    ASSERT_EQUAL(emptyList.back(), 3);
    ASSERT_EQUAL(emptyList.size(),3);

    emptyList.push_back(4);
    ASSERT_EQUAL(emptyList.front(), 1);
    ASSERT_EQUAL(emptyList.back(), 4);
    ASSERT_EQUAL(emptyList.size(),4);
}
//passes
TEST(testing_pop_front_back){
    List<int> emptyList;
    emptyList.push_back(1);
    emptyList.push_back(2);
    emptyList.push_back(3);
    emptyList.push_back(4);
    emptyList.pop_front();
    ASSERT_EQUAL(emptyList.front(), 2);
    ASSERT_EQUAL(emptyList.back(), 4);
    ASSERT_EQUAL(emptyList.size(),3);
    emptyList.pop_back();
    ASSERT_EQUAL(emptyList.front(), 2);
    ASSERT_EQUAL(emptyList.back(), 3);
    ASSERT_EQUAL(emptyList.size(),2);
    emptyList.pop_back();
    ASSERT_EQUAL(emptyList.front(), 2);
    ASSERT_EQUAL(emptyList.back(), 2);
    ASSERT_EQUAL(emptyList.size(),1);
    emptyList.pop_back();
    ASSERT_EQUAL(emptyList.size(),0);
    ASSERT_TRUE(emptyList.empty());
    emptyList.push_back(2);
    emptyList.pop_front();
    ASSERT_EQUAL(emptyList.size(),0);
    ASSERT_TRUE(emptyList.empty());
}

//Passes
TEST(clear_function){
    List<int> emptyList;
    emptyList.push_back(1);
    emptyList.push_back(2);
    emptyList.push_back(3);
    emptyList.push_back(4);
    ASSERT_EQUAL(emptyList.size(),4);
    ASSERT_EQUAL(emptyList.front(), 1);
    ASSERT_EQUAL(emptyList.back(), 4);
    emptyList.clear();
    ASSERT_EQUAL(emptyList.size(),0);
    ASSERT_TRUE(emptyList.empty());
}

//passes
TEST(default_list_constructor){
    List<int> emptyList;
    ASSERT_TRUE(emptyList.empty());
    ASSERT_EQUAL(emptyList.size(),0);
}
//passes
TEST(copy_list_constructor){
    List<int> emptyList;
    emptyList.push_back(1);
    emptyList.push_back(2);
    emptyList.push_back(3);
    emptyList.push_back(4);
    cout << "passes the creation phase" << endl;
    List<int> copiedList = emptyList;
    cout << "passes the copy phase" << endl;
    ASSERT_EQUAL(copiedList.size(),4);
    cout << "passes the size check" << endl;
    int j = 1;
    for (List<int>::Iterator it = copiedList.begin(); it != copiedList.end(); ++it, ++j) {
        std::cout << "At item #" << j << ", get " << *it << std::endl;
        ASSERT_EQUAL(*it, j);
    }
    cout << "passes the data comparison" << endl;
}
//passes
TEST(overload_list_constructor){
    List<int> emptyList;
    emptyList.push_back(1);
    emptyList.push_back(2);
    emptyList.push_back(3);
    emptyList.push_back(4);
    List<int> copiedList = emptyList;
    ASSERT_EQUAL(copiedList.size(),4);
    int j = 1;
    for (List<int>::Iterator it = copiedList.begin(); it != copiedList.end(); ++it, ++j) {
        std::cout << "At item #" << j << ", get " << *it << std::endl;
        ASSERT_EQUAL(*it, j);
    }
}

TEST(iterator_equals_not_equals){
    //Test for two iterators pointing to the same point in the same list.
    List<int> emptyList;
    emptyList.push_back(1);
    emptyList.push_back(2);
    emptyList.push_back(3);
    emptyList.push_back(4);
 
    List<int>::Iterator offset_iterator = emptyList.begin();
    offset_iterator++;
    List<int>::Iterator base_iterator = emptyList.begin();
    List<int>::Iterator base_two_iterator = emptyList.begin();
    for (; offset_iterator != emptyList.end(); ++base_iterator, ++base_two_iterator, ++offset_iterator) {
        std::cout << *base_iterator << " and " << *base_two_iterator << std::endl;
        ASSERT_TRUE(base_iterator == base_two_iterator);
        ASSERT_TRUE(base_iterator == base_two_iterator);
        ASSERT_TRUE(base_iterator != offset_iterator);
        ASSERT_FALSE(base_iterator == offset_iterator);
        ASSERT_FALSE(base_iterator != base_two_iterator);
        ASSERT_FALSE(base_iterator != base_two_iterator);
    }
    ++base_iterator;
    ++base_two_iterator;
    ASSERT_TRUE(base_iterator == base_two_iterator);
    ASSERT_TRUE(base_iterator == base_two_iterator);
    ASSERT_FALSE(base_iterator != base_two_iterator);
    ASSERT_FALSE(base_iterator != base_two_iterator);
    
    //now different lists, should not be the same
    //ACTUALLY, WANT UNDER BEHAVIOR SINCE COMPARING
    //DIFFERENT LISTS!!!!!!  
    // List<int> copiedList = emptyList;
    // base_two_iterator = copiedList.begin();
    // offset_iterator = copiedList.begin();
    // offset_iterator++;
    // base_iterator = emptyList.begin();
    // for (; offset_iterator != copiedList.end(); ++base_iterator, ++base_two_iterator, ++offset_iterator) {
    //     std::cout << *base_iterator << " and " << *base_two_iterator << std::endl;
    //     if(base_iterator == emptyList.begin()){
    //         --offset_iterator;
    //     }
    //     std::cout << *base_iterator << " and " << *base_two_iterator << std::endl;
    //     ASSERT_TRUE(base_iterator != base_two_iterator);
    //     ASSERT_TRUE(base_iterator != base_two_iterator);
    //     ASSERT_TRUE(base_iterator != offset_iterator);
    //     ASSERT_FALSE(base_iterator == offset_iterator);
    //     ASSERT_FALSE(base_iterator == base_two_iterator);
    //     ASSERT_FALSE(base_iterator == base_two_iterator);
    // }
    // ++base_iterator;
    // ++base_two_iterator;
    // ASSERT_FALSE(base_iterator != base_two_iterator);
    // ASSERT_FALSE(base_iterator != base_two_iterator);
    // ASSERT_TRUE(base_iterator == base_two_iterator);
    // ASSERT_TRUE(base_iterator == base_two_iterator);
}

TEST(iterator_constructor_default){
    List<int> emptyList;
    emptyList.push_back(1);
    emptyList.push_back(2);
    emptyList.push_back(3);
    emptyList.push_back(4);
    List<int> copiedList = emptyList;
    ASSERT_EQUAL(copiedList.size(),4);
    int j = 1;
    for (List<int>::Iterator it = copiedList.begin(); it != copiedList.end(); ++it, ++j) {
        std::cout << "At item #" << j << ", get " << *it << std::endl;
        ASSERT_EQUAL(*it, j);
    }
}

TEST(iterator_constructor_copy){
    List<int> emptyList;
    emptyList.push_back(1);
    emptyList.push_back(2);
    emptyList.push_back(3);
    emptyList.push_back(4);
    int j = 1;
    List<int>::Iterator it = emptyList.begin();
    List<int>::Iterator it2(it);
    for (; it != emptyList.end(); ++it, ++it2, ++j) {
        std::cout << "At item #" << j << ", get " << *it << " and " << *it2 << std::endl;
        ASSERT_TRUE(it == it2);
    }
}

TEST(iterator_constructor_overload){
    List<int> emptyList;
    emptyList.push_back(1);
    emptyList.push_back(2);
    emptyList.push_back(3);
    emptyList.push_back(4);
    int j = 1;
    List<int>::Iterator it = emptyList.begin();
    List<int>::Iterator it2 = it;
    for (; it != emptyList.end(); ++it, ++it2, ++j) {
        std::cout << "At item #" << j << ", get " << *it << " and " << *it2 << std::endl;
        ASSERT_TRUE(it == it2);
    }
}

//not all tests
TEST(iterator_increment_decrement_prefix_1){
    List<int> emptyList;
    emptyList.push_back(1);
    emptyList.push_back(2);
    emptyList.push_back(3);
    emptyList.push_back(4);
    List<int>::Iterator it = emptyList.begin();
    List<int>::Iterator it2 = it;
    it++;
    it2++;
    ASSERT_TRUE(*(it++) == *(it2--));
    it--;
    it2++;
    ASSERT_FALSE(*(++it) == *(--it2));
    it--;
    it2++;
    ASSERT_FALSE(*(it++) == *(--it2));
    it--;
    it2++;
    ASSERT_FALSE(*(++it) == *(it2--));
}

TEST(iterator_increment_decrement_prefix_standard){
    List<int> emptyList;
    emptyList.push_back(1);
    emptyList.push_back(2);
    emptyList.push_back(3);
    emptyList.push_back(4);
    List<int>::Iterator it = emptyList.end();
    int j = 4;
    for (; it != emptyList.begin(); --it, --j) {
        std::cout << "At item #" << j << ", get " << *it << std::endl;
        ASSERT_TRUE(*it == j);
    }

    j = 1;
    it = emptyList.begin();
    for (; it != emptyList.end(); ++it, ++j) {
        std::cout << "At item #" << j << ", get " << *it << std::endl;
        ASSERT_TRUE(*it == j);
    }
}

TEST(iterator_increment_decrement_prefix_one_elem){
    List<int> emptyList;
    emptyList.push_back(1);
    List<int>::Iterator it = emptyList.end();
    int j = 1;
    for (; it != emptyList.begin(); --it, --j) {
        std::cout << "At item #" << j << ", get " << *it << std::endl;
        ASSERT_TRUE(*it == j);
    }

    j = 1;
    it = emptyList.begin();
    for (; it != emptyList.end(); ++it, ++j) {
        std::cout << "At item #" << j << ", get " << *it << std::endl;
        ASSERT_TRUE(*it == j);
    }
}

TEST(iterator_increment_decrement_prefix_two_elem){
    List<int> emptyList;
    emptyList.push_back(1);
    emptyList.push_back(2);
    List<int>::Iterator it = emptyList.end();
    int j = 2;
    for (; it != emptyList.begin(); --it, --j) {
        std::cout << "At item #" << j << ", get " << *it << std::endl;
        ASSERT_TRUE(*it == j);
    }

    j = 1;
    it = emptyList.begin();
    for (; it != emptyList.end(); ++it, ++j) {
        std::cout << "At item #" << j << ", get " << *it << std::endl;
        ASSERT_TRUE(*it == j);
    }
}

TEST(iterator_erase_insert){
    List<int> emptyList;
    emptyList.push_back(1);
    emptyList.push_back(2);
    emptyList.push_back(3);
    emptyList.push_back(4);
    List<int>::Iterator it = emptyList.end();
    List<int>::Iterator it2(it);
    List<int>::Iterator it3;
    emptyList.clear();
    ASSERT_TRUE(it == it2);
    ASSERT_FALSE(it == it3);
    ASSERT_FALSE(it2 == it3);
    
    
    //assert works properly for all the different types
    //of iterators...



    
}

// TEST(default_iterator_constructor){
//     List<int> emptyList;
//     List<int>::Iterator empty;
    
//     emptyList.push_back(1);
//     emptyList.push_back(2);
//     emptyList.push_back(3);
//     emptyList.push_back(4);

// }

//Test reverse iteration
//Test prefix and postfix operators
//

TEST_MAIN()
