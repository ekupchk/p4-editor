#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

//Empty execution
TEST(testing_empty_default) {
    //Checking consecuitve executions 
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

//Copy constructor execution
TEST(testing_empty_copy) {
    //Checking consecuitve executions 
    List<int> base_maker;
    List<int> emptyList = base_maker;
    ASSERT_TRUE(emptyList.empty());
    ASSERT_TRUE(emptyList.empty());
    std::cout << "Consecutive test of copy empty passed" << std::endl;

    ASSERT_TRUE(base_maker.empty());
    for (int i = 0; i < 5; ++i) {
        base_maker.push_back(i);
    }
    List<int> emptyList2 = base_maker;
    ASSERT_FALSE(emptyList2.empty());
    ASSERT_FALSE(emptyList2.empty());
    std::cout << "Test of copy empty pre and post filled passed" << std::endl;

    int j = 0;
    for (List<int>::Iterator it = emptyList2.begin(); it != emptyList2.end(); ++it, ++j) {
        std::cout << "At item #" << j << ", get " << *it << std::endl;
        ASSERT_EQUAL(*it, j);
    }

    std::cout << "Test of prefilled list variable modifications passed" << std::endl;
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


TEST(testing_front_back){
    List<int> emptyList;

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
    ASSERT_EQUAL(emptyList.back(), 10);
    ASSERT_EQUAL(emptyList.back(), 10);

    //Added to end behavior works
    emptyList.push_back(3);
    ASSERT_EQUAL(emptyList.front(), 7);
    ASSERT_EQUAL(emptyList.front(), 7);
    ASSERT_EQUAL(emptyList.back(), 3);
    ASSERT_EQUAL(emptyList.back(), 3);

    //duplicate case so no change expected
    emptyList.push_front(3);
    ASSERT_EQUAL(emptyList.front(), 7);
    ASSERT_EQUAL(emptyList.front(), 7);
    ASSERT_EQUAL(emptyList.back(), 3);
    ASSERT_EQUAL(emptyList.back(), 3);

    //7 10 3 is list
    emptyList.pop_back();
    ASSERT_EQUAL(emptyList.front(), 7);
    ASSERT_EQUAL(emptyList.front(), 7);
    ASSERT_EQUAL(emptyList.back(), 10);
    ASSERT_EQUAL(emptyList.back(), 10);

    emptyList.pop_front();
    ASSERT_EQUAL(emptyList.front(), 10);
    ASSERT_EQUAL(emptyList.front(), 10);
    ASSERT_EQUAL(emptyList.back(), 10);
    ASSERT_EQUAL(emptyList.back(), 10);
}

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

TEST(default_iterator_constructor){
    List<int> emptyList;
    List<int>::Iterator empty;
    
    emptyList.push_back(1);
    emptyList.push_back(2);
    emptyList.push_back(3);
    emptyList.push_back(4);

}

TEST_MAIN()
