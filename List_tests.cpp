#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

//Empty execution
TEST(testing_empty_clear_size_default) {
    int index_val;
    List<int> emptyList;
    //checking base case of default untouched
    ASSERT_TRUE(emptyList.empty());
    ASSERT_TRUE(emptyList.size() == 0);
    //checking if default untouched, recleared list case works
    emptyList.clear();
    ASSERT_TRUE(emptyList.empty());
    ASSERT_TRUE(emptyList.size() == 0);
    //Not checkable since front and back are private
    //ASSERT_TRUE(emptyList->front == nullptr);
    std::cout << "base empty list properties check" << std::endl;


    List<int> emptyList2;
    //already confirmed base case works for empty
    //using push back or front makes no difference for this test
    //checked for differences in later section
    emptyList2.push_back(10);
    ASSERT_FALSE(emptyList2.empty());
    ASSERT_TRUE(emptyList2.size() == 1);
    ASSERT_TRUE(emptyList2.front() == 10);
    ASSERT_TRUE(emptyList2.back() == 10);
    ASSERT_FALSE(emptyList2.empty());
    ASSERT_TRUE(emptyList2.size() == 1);
    ASSERT_TRUE(emptyList2.front() == 10);
    ASSERT_TRUE(emptyList2.back() == 10);
    //checking that multiple executions cause no issues
    //with modified items or list size
    emptyList2.clear();
    ASSERT_TRUE(emptyList2.empty());
    ASSERT_TRUE(emptyList2.size() == 0);
    ASSERT_TRUE(emptyList2.empty());
    ASSERT_TRUE(emptyList2.size() == 0);
    //ensuring that after item cotaining list is cleared,
    //empty works correctly
    std::cout << "base constructed one item-contained list properties check" << std::endl;

    List<int> emptyList3;
    //already confirmed base case works for empty
    //using push back or front makes no difference for this test
    //checked for differences in later section
    emptyList3.push_back(10);
    emptyList3.push_back(20);
    ASSERT_FALSE(emptyList3.empty());
    ASSERT_TRUE(emptyList3.size() == 2);
    ASSERT_TRUE(emptyList3.front() == 10);
    ASSERT_TRUE(emptyList3.back() == 20);
    ASSERT_FALSE(emptyList3.empty());
    ASSERT_TRUE(emptyList3.size() == 2);
    ASSERT_TRUE(emptyList3.front() == 10);
    ASSERT_TRUE(emptyList3.back() == 20);
    //checking that multiple executions cause no issues
    //with modified items or list size
    emptyList3.clear();
    ASSERT_TRUE(emptyList3.empty());
    ASSERT_TRUE(emptyList3.size() == 0);
    ASSERT_TRUE(emptyList3.empty());
    ASSERT_TRUE(emptyList3.size() == 0);
    //ensuring that after item cotaining list is cleared,
    //empty works correctly
    std::cout << "base constructed two item-contained list properties check" << std::endl;

    //Testing for consecutive additions with 
    //push front and push back
    //checking size as additions are made
    List<int> emptyList4;
    ASSERT_TRUE(emptyList4.empty());
    ASSERT_TRUE(emptyList4.size() == 0);
    for (int i = 0; i < 5; ++i) {
        index_val = (i+1)*10;
        emptyList4.push_back(index_val);
        ASSERT_FALSE(emptyList4.empty());
        ASSERT_TRUE(emptyList4.size() == (i+1));
        ASSERT_TRUE(emptyList4.front() == 10);
        ASSERT_TRUE(emptyList4.back() == index_val);
    }
    ASSERT_FALSE(emptyList4.empty());
    emptyList4.clear();
    ASSERT_TRUE(emptyList4.empty());
    ASSERT_TRUE(emptyList4.size() == 0);
    ASSERT_TRUE(emptyList4.empty());
    ASSERT_TRUE(emptyList4.size() == 0);
    
    for (int i = 0; i < 5; ++i) {
        index_val = (5-i)*10;
        emptyList4.push_front(index_val);
        ASSERT_FALSE(emptyList4.empty());
        ASSERT_TRUE(emptyList4.size() == (i+1));
        ASSERT_TRUE(emptyList4.front() == index_val);
        ASSERT_TRUE(emptyList4.back() == 50);
    }
    ASSERT_FALSE(emptyList4.empty());
    emptyList4.clear();
    ASSERT_TRUE(emptyList4.empty());
    ASSERT_TRUE(emptyList4.size() == 0);
    ASSERT_TRUE(emptyList4.empty());
    ASSERT_TRUE(emptyList4.size() == 0);
    
    
    List<int> emptyList5;
    //makes no difference if push front or back
    //for this test, checking difference with pop front and back
    for (int i = 0; i < 5; ++i) {
        index_val = (i+1)*10;
        emptyList5.push_back(index_val);
    }
    ASSERT_FALSE(emptyList5.empty());
    ASSERT_TRUE(emptyList5.size() == 5);
    ASSERT_TRUE(emptyList5.front() == 10);
    ASSERT_TRUE(emptyList5.back() == 50);
    for(int i = 5; i > 0; --i){
        index_val = (7-i)*10;
        emptyList5.pop_front();
        if(i == 1){
            ASSERT_TRUE(emptyList5.empty());
            ASSERT_TRUE(emptyList5.size() == (i-1));
        }else{
            ASSERT_FALSE(emptyList5.empty());
            ASSERT_TRUE(emptyList5.size() == (i-1));
            cout << "testing the front number " << index_val << endl;
            cout << emptyList5.front() << endl;
            ASSERT_TRUE(emptyList5.front() == index_val);
            ASSERT_TRUE(emptyList5.back() == 50);
        }
    }

    //now repeat checks for the pop_back variant
    for (int i = 0; i < 5; ++i) {
        emptyList5.push_back((i+1)*10);
    }
    ASSERT_FALSE(emptyList5.empty());
    ASSERT_TRUE(emptyList5.size() == 5);
    ASSERT_TRUE(emptyList5.front() == 10);
    ASSERT_TRUE(emptyList5.back() == 50);
    for(int i = 5; i > 0; --i){
        emptyList5.pop_back();
        index_val = ((i-1)*10);
        if(i == 1){
            ASSERT_TRUE(emptyList5.empty());
            ASSERT_TRUE(emptyList5.size() == (i-1));
        }else{
            ASSERT_FALSE(emptyList5.empty());
            ASSERT_TRUE(emptyList5.size() == (i-1));
            ASSERT_TRUE(emptyList5.front() == 10);
            cout << "testing the back number " << index_val << endl;
            cout << emptyList5.back() << endl;
            ASSERT_TRUE(emptyList5.back() == index_val);
        }
    }


    // List<int> copyList;
    // copyList = emptyList4;
    // ASSERT_FALSE(copyList.empty());
    // ASSERT_FALSE(copyList.empty());
    // //Testing the basic copy list with filled elements

    // List<int> overloadList(emptyList4);
    // ASSERT_FALSE(overloadList.empty());
    // ASSERT_FALSE(overloadList.empty());
    // //Testing the basic overload list of filled elements
    // std::cout << "Test of default empty pre and post filled passed" << std::endl;


    // std::cout << "Test of prefilled list variable modifications passed" << std::endl;
}

TEST(testing_empty_clear_size_copy_made) {
    List<int> copyBase;
    List<int> emptyList;
    int index_val;
    emptyList = copyBase;
    //checking base case of default untouched
    ASSERT_TRUE(emptyList.empty());
    ASSERT_TRUE(emptyList.size() == 0);
    //checking if default untouched, recleared list case works
    emptyList.clear();
    ASSERT_TRUE(emptyList.empty());
    ASSERT_TRUE(emptyList.size() == 0);
    //Not checkable since front and back are private
    //ASSERT_TRUE(emptyList->front == nullptr);
    std::cout << "copied empty list properties check" << std::endl;

    List<int> copyBase2;
    copyBase2.push_back(10);
    List<int> emptyList2;
    emptyList2 = copyBase2;
    //already confirmed base case works for empty
    //using push back or front makes no difference for this test
    //checked for differences in later section
    ASSERT_FALSE(emptyList2.empty());
    ASSERT_TRUE(emptyList2.size() == 1);
    ASSERT_TRUE(emptyList2.front() == 10);
    ASSERT_TRUE(emptyList2.back() == 10);
    ASSERT_FALSE(emptyList2.empty());
    ASSERT_TRUE(emptyList2.size() == 1);
    ASSERT_TRUE(emptyList2.front() == 10);
    ASSERT_TRUE(emptyList2.back() == 10);
    //checking that multiple executions cause no issues
    //with modified items or list size
    emptyList2.clear();
    ASSERT_TRUE(emptyList2.empty());
    ASSERT_TRUE(emptyList2.size() == 0);
    ASSERT_TRUE(emptyList2.empty());
    ASSERT_TRUE(emptyList2.size() == 0);
    //make sure the copyBase2 does not change
    //should not be the same exact nodes
    ASSERT_FALSE(copyBase2.empty());
    ASSERT_TRUE(copyBase2.size() == 1);
    ASSERT_TRUE(copyBase2.front() == 10);
    ASSERT_TRUE(copyBase2.back() == 10);
    //ensuring that after item cotaining list is cleared,
    //empty works correctly
    std::cout << "copy constructed one item-contained list properties check" << std::endl;

    List<int> copyBase3;
    copyBase3.push_back(10);
    copyBase3.push_back(20);
    List<int> emptyList3;
    emptyList3 = copyBase3;
    //already confirmed base case works for empty
    //using push back or front makes no difference for this test
    //checked for differences in later section
    ASSERT_FALSE(emptyList3.empty());
    ASSERT_TRUE(emptyList3.size() == 2);
    ASSERT_TRUE(emptyList3.front() == 10);
    ASSERT_TRUE(emptyList3.back() == 20);
    ASSERT_FALSE(emptyList3.empty());
    ASSERT_TRUE(emptyList3.size() == 2);
    ASSERT_TRUE(emptyList3.front() == 10);
    ASSERT_TRUE(emptyList3.back() == 20);
    //checking that multiple executions cause no issues
    //with modified items or list size
    emptyList3.clear();
    ASSERT_TRUE(emptyList3.empty());
    ASSERT_TRUE(emptyList3.size() == 0);
    ASSERT_TRUE(emptyList3.empty());
    ASSERT_TRUE(emptyList3.size() == 0);
    //make sure the copyBase3 does not change
    //should not be the same exact nodes
    ASSERT_FALSE(copyBase3.empty());
    ASSERT_TRUE(copyBase3.size() == 2);
    ASSERT_TRUE(copyBase3.front() == 10);
    ASSERT_TRUE(copyBase3.back() == 20);
    //ensuring that after item cotaining list is cleared,
    //empty works correctly
    std::cout << "base constructed two item-contained list properties check" << std::endl;

    //Testing for consecutive additions with 
    //push front and push back
    //checking size as additions are made
    //Also making sure that after the copy list is made,
    //changes can be made to the copy list
    List<int> copyBase4;
    copyBase4.push_back(10);
    copyBase4.push_back(20);
    List<int> emptyList4;
    emptyList4 = copyBase4;
    for (int i = 2; i < 5; ++i) {
        index_val = (i+1)*10;
        emptyList4.push_back(index_val);
        ASSERT_FALSE(emptyList4.empty());
        ASSERT_TRUE(emptyList4.size() == (i+1));
        ASSERT_TRUE(emptyList4.front() == 10);
        ASSERT_TRUE(emptyList4.back() == (index_val));
    }
    ASSERT_FALSE(emptyList4.empty());
    emptyList4.clear();
    ASSERT_TRUE(emptyList4.empty());
    ASSERT_TRUE(emptyList4.size() == 0);
    ASSERT_TRUE(emptyList4.empty());
    ASSERT_TRUE(emptyList4.size() == 0);
    ASSERT_FALSE(copyBase4.empty());
    ASSERT_TRUE(copyBase4.size() == 2);
    ASSERT_TRUE(copyBase4.front() == 10);
    ASSERT_TRUE(copyBase4.back() == 20);
    copyBase4.clear();

    copyBase4.push_back(40);
    copyBase4.push_back(50);
    emptyList4 = copyBase4;
    //should be able to push into the list since cleared
    for (int i = 2; i < 5; ++i) {
        index_val = (5-i)*10;
        emptyList4.push_front(index_val);
        ASSERT_FALSE(emptyList4.empty());
        ASSERT_TRUE(emptyList4.size() == (i+1));
        ASSERT_TRUE(emptyList4.front() == (index_val));
        ASSERT_TRUE(emptyList4.back() == 50);
    }
    ASSERT_FALSE(emptyList4.empty());
    emptyList4.clear();
    ASSERT_TRUE(emptyList4.empty());
    ASSERT_TRUE(emptyList4.size() == 0);
    ASSERT_TRUE(emptyList4.empty());
    ASSERT_TRUE(emptyList4.size() == 0);
    ASSERT_FALSE(copyBase4.empty());
    ASSERT_TRUE(copyBase4.size() == 2);
    ASSERT_TRUE(copyBase4.front() == 40);
    ASSERT_TRUE(copyBase4.back() == 50);
    copyBase4.clear();


    List<int> copyBase5;
    List<int> emptyList5;
    //makes no difference if push front or back
    //for this test, checking difference with pop front and back
    for (int i = 0; i < 5; ++i) {
        index_val = (i+1)*10;
        copyBase5.push_back(index_val);
    }
    emptyList5 = copyBase5;
    ASSERT_FALSE(emptyList5.empty());
    ASSERT_TRUE(emptyList5.size() == 5);
    ASSERT_TRUE(emptyList5.front() == 10);
    ASSERT_TRUE(emptyList5.back() == 50);
    for(int i = 5; i > 0; --i){
        emptyList5.pop_front();
        index_val = (7-i)*10;
        if(i == 1){
            ASSERT_TRUE(emptyList5.empty());
            ASSERT_TRUE(emptyList5.size() == (i-1));
        }else{
            ASSERT_FALSE(emptyList5.empty());
            ASSERT_TRUE(emptyList5.size() == (i-1));
            cout << "testing the front number " << index_val << endl;
            cout << emptyList5.front() << endl;
            ASSERT_TRUE(emptyList5.front() == index_val);
            ASSERT_TRUE(emptyList5.back() == 50);
        }
    }
    ASSERT_FALSE(copyBase5.empty());
    ASSERT_TRUE(copyBase5.size() == 5);
    ASSERT_TRUE(copyBase5.front() == 10);
    ASSERT_TRUE(copyBase5.back() == 50);
    copyBase5.clear();
    //now repeat checks for the pop_back variant
    for (int i = 0; i < 5; ++i) {
        index_val = (i+1)*10;
        copyBase5.push_back(index_val);
    }
    emptyList5 = copyBase5;
    ASSERT_FALSE(emptyList5.empty());
    ASSERT_TRUE(emptyList5.size() == 5);
    ASSERT_TRUE(emptyList5.front() == 10);
    ASSERT_TRUE(emptyList5.back() == 50);
    for(int i = 5; i > 0; --i){
        emptyList5.pop_back();
        index_val = (i*10)-10;
        if(i == 1){
            ASSERT_TRUE(emptyList5.empty());
            ASSERT_TRUE(emptyList5.size() == (i-1));
        }else{
            ASSERT_FALSE(emptyList5.empty());
            ASSERT_TRUE(emptyList5.size() == (i-1));
            ASSERT_TRUE(emptyList5.front() == 10);
            cout << "testing the back number " << index_val << endl;
            cout << emptyList5.back() << endl;
            ASSERT_TRUE(emptyList5.back() == index_val);
        }
    }
    ASSERT_FALSE(copyBase5.empty());
    ASSERT_TRUE(copyBase5.size() == 5);
    ASSERT_TRUE(copyBase5.front() == 10);
    ASSERT_TRUE(copyBase5.back() == 50);
}

TEST(testing_empty_clear_size_override_made) {
    int index_val;
    List<int> copyBase;
    List<int> emptyList(copyBase);
    //checking base case of default untouched
    ASSERT_TRUE(emptyList.empty());
    ASSERT_TRUE(emptyList.size() == 0);
    //checking if default untouched, recleared list case works
    emptyList.clear();
    ASSERT_TRUE(emptyList.empty());
    ASSERT_TRUE(emptyList.size() == 0);
    //Not checkable since front and back are private
    //ASSERT_TRUE(emptyList->front == nullptr);
    std::cout << "copied empty list properties check" << std::endl;

    List<int> copyBase2;
    copyBase2.push_back(10);
    List<int> emptyList2(copyBase2);
    //already confirmed base case works for empty
    //using push back or front makes no difference for this test
    //checked for differences in later section
    ASSERT_FALSE(emptyList2.empty());
    ASSERT_TRUE(emptyList2.size() == 1);
    ASSERT_TRUE(emptyList2.front() == 10);
    ASSERT_TRUE(emptyList2.back() == 10);
    ASSERT_FALSE(emptyList2.empty());
    ASSERT_TRUE(emptyList2.size() == 1);
    ASSERT_TRUE(emptyList2.front() == 10);
    ASSERT_TRUE(emptyList2.back() == 10);
    //checking that multiple executions cause no issues
    //with modified items or list size
    emptyList2.clear();
    ASSERT_TRUE(emptyList2.empty());
    ASSERT_TRUE(emptyList2.size() == 0);
    ASSERT_TRUE(emptyList2.empty());
    ASSERT_TRUE(emptyList2.size() == 0);
    //make sure the copyBase2 does not change
    //should not be the same exact nodes
    ASSERT_FALSE(copyBase2.empty());
    ASSERT_TRUE(copyBase2.size() == 1);
    ASSERT_TRUE(copyBase2.front() == 10);
    ASSERT_TRUE(copyBase2.back() == 10);
    //ensuring that after item cotaining list is cleared,
    //empty works correctly
    std::cout << "copy constructed one item-contained list properties check" << std::endl;

    List<int> copyBase3;
    copyBase3.push_back(10);
    copyBase3.push_back(20);
    List<int> emptyList3(copyBase3);
    //already confirmed base case works for empty
    //using push back or front makes no difference for this test
    //checked for differences in later section
    ASSERT_FALSE(emptyList3.empty());
    ASSERT_TRUE(emptyList3.size() == 2);
    ASSERT_TRUE(emptyList3.front() == 10);
    ASSERT_TRUE(emptyList3.back() == 20);
    ASSERT_FALSE(emptyList3.empty());
    ASSERT_TRUE(emptyList3.size() == 2);
    ASSERT_TRUE(emptyList3.front() == 10);
    ASSERT_TRUE(emptyList3.back() == 20);
    //checking that multiple executions cause no issues
    //with modified items or list size
    emptyList3.clear();
    ASSERT_TRUE(emptyList3.empty());
    ASSERT_TRUE(emptyList3.size() == 0);
    ASSERT_TRUE(emptyList3.empty());
    ASSERT_TRUE(emptyList3.size() == 0);
    //make sure the copyBase3 does not change
    //should not be the same exact nodes
    ASSERT_FALSE(copyBase3.empty());
    ASSERT_TRUE(copyBase3.size() == 2);
    ASSERT_TRUE(copyBase3.front() == 10);
    ASSERT_TRUE(copyBase3.back() == 20);
    //ensuring that after item cotaining list is cleared,
    //empty works correctly
    std::cout << "base constructed two item-contained list properties check" << std::endl;

    //Testing for consecutive additions with 
    //push front and push back
    //checking size as additions are made
    //Also making sure that after the copy list is made,
    //changes can be made to the copy list
    List<int> copyBase4;
    copyBase4.push_back(10);
    copyBase4.push_back(20);
    List<int> emptyList4(copyBase4);
    for (int i = 2; i < 5; ++i) {
        index_val = (i+1)*10;
        emptyList4.push_back(index_val);
        ASSERT_FALSE(emptyList4.empty());
        ASSERT_TRUE(emptyList4.size() == (i+1));
        ASSERT_TRUE(emptyList4.front() == 10);
        ASSERT_TRUE(emptyList4.back() == (index_val));
    }
    ASSERT_FALSE(emptyList4.empty());
    emptyList4.clear();
    ASSERT_TRUE(emptyList4.empty());
    ASSERT_TRUE(emptyList4.size() == 0);
    ASSERT_TRUE(emptyList4.empty());
    ASSERT_TRUE(emptyList4.size() == 0);
    ASSERT_FALSE(copyBase4.empty());
    ASSERT_TRUE(copyBase4.size() == 2);
    ASSERT_TRUE(copyBase4.front() == 10);
    ASSERT_TRUE(copyBase4.back() == 20);
    copyBase4.clear();

    copyBase4.push_back(40);
    copyBase4.push_back(50);
    List<int> emptyList4other(copyBase4);
    //should be able to push into the list since cleared
    for (int i = 2; i < 5; ++i) {
        index_val = (5-i)*10;
        emptyList4other.push_front(index_val);
        ASSERT_FALSE(emptyList4other.empty());
        cout << i+1 << " is the size expected" << endl;
        cout << emptyList4other.size() << " is actual size" << endl;
        cout << "testing the front number " << index_val << endl;
        cout << emptyList4other.front() << endl;
        ASSERT_TRUE(emptyList4other.size() == (i+1));
        ASSERT_TRUE(emptyList4other.front() == (index_val));
        ASSERT_TRUE(emptyList4other.back() == 50);
    }
    ASSERT_FALSE(emptyList4other.empty());
    emptyList4other.clear();
    ASSERT_TRUE(emptyList4other.empty());
    ASSERT_TRUE(emptyList4other.size() == 0);
    ASSERT_TRUE(emptyList4other.empty());
    ASSERT_TRUE(emptyList4other.size() == 0);
    ASSERT_FALSE(copyBase4.empty());
    ASSERT_TRUE(copyBase4.size() == 2);
    ASSERT_TRUE(copyBase4.front() == 40);
    ASSERT_TRUE(copyBase4.back() == 50);
    copyBase4.clear();


    List<int> copyBase5;
    //makes no difference if push front or back
    //for this test, checking difference with pop front and back
    for (int i = 0; i < 5; ++i) {
        index_val = (i+1)*10;
        copyBase5.push_back(index_val);
    }
    List<int> emptyList5(copyBase5);
    ASSERT_FALSE(emptyList5.empty());
    ASSERT_TRUE(emptyList5.size() == 5);
    ASSERT_TRUE(emptyList5.front() == 10);
    ASSERT_TRUE(emptyList5.back() == 50);
    for(int i = 5; i > 0; --i){
        emptyList5.pop_front();
        index_val = (7-i)*10;
        if(i == 1){
            ASSERT_TRUE(emptyList5.empty());
            ASSERT_TRUE(emptyList5.size() == (i-1));
        }else{
            ASSERT_FALSE(emptyList5.empty());
            ASSERT_TRUE(emptyList5.size() == (i-1));
            cout << "testing the front number " << index_val << endl;
            cout << emptyList5.front() << endl;
            ASSERT_TRUE(emptyList5.front() == index_val);
            ASSERT_TRUE(emptyList5.back() == 50);
        }
    }
    ASSERT_FALSE(copyBase5.empty());
    ASSERT_TRUE(copyBase5.size() == 5);
    ASSERT_TRUE(copyBase5.front() == 10);
    ASSERT_TRUE(copyBase5.back() == 50);
    copyBase5.clear();
    //now repeat checks for the pop_back variant
    for (int i = 0; i < 5; ++i) {
        index_val = (i+1)*10;
        copyBase5.push_back(index_val);
    }
    List<int> emptyList5other(copyBase5);
    ASSERT_FALSE(emptyList5other.empty());
    ASSERT_TRUE(emptyList5other.size() == 5);
    ASSERT_TRUE(emptyList5other.front() == 10);
    ASSERT_TRUE(emptyList5other.back() == 50);
    for(int i = 5; i > 0; --i){
        emptyList5other.pop_back();
        index_val = (i*10)-10;
        if(i == 1){
            ASSERT_TRUE(emptyList5other.empty());
            ASSERT_TRUE(emptyList5other.size() == (i-1));
        }else{
            ASSERT_FALSE(emptyList5other.empty());
            ASSERT_TRUE(emptyList5other.size() == (i-1));
            ASSERT_TRUE(emptyList5other.front() == 10);
            cout << "testing the back number " << index_val << endl;
            cout << emptyList5other.back() << endl;
            ASSERT_TRUE(emptyList5other.back() == index_val);
        }
    }
    ASSERT_FALSE(copyBase5.empty());
    ASSERT_TRUE(copyBase5.size() == 5);
    ASSERT_TRUE(copyBase5.front() == 10);
    ASSERT_TRUE(copyBase5.back() == 50);
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
    List<int> copiedList;
    copiedList = emptyList;
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
    //This line alone doesn't test the overload constructor
    //List<int> copiedList = emptyList;
    List<int> copiedList(emptyList);
    ASSERT_EQUAL(copiedList.size(),4);
    int j = 1;
    for (List<int>::Iterator it = copiedList.begin(); it != copiedList.end(); ++it, ++j) {
        std::cout << "At item #" << j << ", get " << *it << std::endl;
        ASSERT_EQUAL(*it, j);
    }
}

//passes
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
//passes
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

//passes
TEST(iterator_constructor_overload){
    List<int> emptyList;
    emptyList.push_back(1);
    emptyList.push_back(2);
    emptyList.push_back(3);
    emptyList.push_back(4);
    int j = 1;
    List<int>::Iterator it = emptyList.begin();
    //not enough to test overloading
    List<int>::Iterator it2;
    it2 = it;
    for (; it != emptyList.end(); ++it) {
        std::cout << "At item #" << j << ", get " << *it << " and " << *it2 << std::endl;
        ASSERT_TRUE(it == it2);
        ++j;
        ++it2;
    }
}

//not all tests
//passes
TEST(iterator_increment_decrement_prefix_1){
    List<int> emptyList;
    emptyList.push_back(1);
    emptyList.push_back(2);
    List<int>::Iterator it = emptyList.end();
    List<int>::Iterator it2;
    it2 = it;
    while(it != emptyList.begin()){
        ASSERT_TRUE(*(it--) == *(it2--));
    }

    emptyList.push_back(3);
    emptyList.push_back(4);
    List<int>::Iterator it3 = emptyList.begin();
    List<int>::Iterator it4;
    it4 = it3;
    while(it4 != emptyList.end()){
        ASSERT_TRUE(*(it3++) == *(it4++));
    }


    // it++;
    // it2++;
    // ASSERT_TRUE(*(it++) == *(it2--));
    // it--;
    // it2++;
    // ASSERT_FALSE(*(++it) == *(--it2));
    // it--;
    // it2++;
    // ASSERT_FALSE(*(it++) == *(--it2));
    // it--;
    // it2++;
    // ASSERT_FALSE(*(++it) == *(it2--));


}

// TEST(iterator_increment_decrement_prefix_standard){
//     List<int> emptyList;
//     emptyList.push_back(1);
//     emptyList.push_back(2);
//     emptyList.push_back(3);
//     emptyList.push_back(4);
//     List<int>::Iterator it = emptyList.end();
//     int j = 4;
//     ASSERT_TRUE(*it == 4);
//     for (; it != emptyList.begin(); --it, --j) {
//         std::cout << "At item #" << j << ", get " << *it << std::endl;
//         ASSERT_TRUE(*it == j);
//     }
//     j = 1;
//     it = emptyList.begin();
//     for (; it != emptyList.end(); ++it, ++j) {
//         std::cout << "At item #" << j << ", get " << *it << std::endl;
//         ASSERT_TRUE(*it == j);
//     }
// }

// TEST(iterator_increment_decrement_prefix_one_elem){
//     List<int> emptyList;
//     emptyList.push_back(1);
//     List<int>::Iterator it = emptyList.end();
//     int j = 1;
//     for (; it != emptyList.begin(); --it, --j) {
//         std::cout << "At item #" << j << ", get " << *it << std::endl;
//         ASSERT_TRUE(*it == j);
//     }
//     j = 1;
//     it = emptyList.begin();
//     for (; it != emptyList.end(); ++it, ++j) {
//         std::cout << "At item #" << j << ", get " << *it << std::endl;
//         ASSERT_TRUE(*it == j);
//     }
// }

// TEST(iterator_increment_decrement_prefix_two_elem){
//     List<int> emptyList;
//     emptyList.push_back(1);
//     emptyList.push_back(2);
//     List<int>::Iterator it = emptyList.end();
//     int j = 2;
//     for (; it != emptyList.begin(); --it, --j) {
//         std::cout << "At item #" << j << ", get " << *it << std::endl;
//         ASSERT_TRUE(*it == j);
//     }
//     j = 1;
//     it = emptyList.begin();
//     for (; it != emptyList.end(); ++it, ++j) {
//         std::cout << "At item #" << j << ", get " << *it << std::endl;
//         ASSERT_TRUE(*it == j);
//     }
// }

//passes
TEST(iterator_comparisons){
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
    //Fails here, the T operator*(){ function fails
    ASSERT_FALSE(it == it3);
    ASSERT_FALSE(it2 == it3);
    ASSERT_FALSE(it != it2);
    ASSERT_TRUE(it != it3);
    ASSERT_TRUE(it2 != it3);
    
    List<int>::Iterator it4;
    ASSERT_TRUE(it3 == it4);
    ASSERT_TRUE(it3 == it4);
    ASSERT_FALSE(it3 != it4);
    ASSERT_FALSE(it3 != it4);
    //assert works properly for all the different types
    //of iterators...   
}

TEST(modifiable_iterators){
    List<int> emptyList;
    emptyList.push_back(1);
    emptyList.push_back(2);
    emptyList.push_back(3);
    emptyList.push_back(4);
    int j = 1;
    List<int>::Iterator iter = emptyList.begin();
    for (; iter != emptyList.end(); ++iter, ++j) {
        std::cout << "At item #" << j << ", get " << *iter << std::endl;
        ASSERT_TRUE(*iter == j);
    }
    //WHY NOT WORKING, must be modifiable lvalue?
    //*(iter++) = 280;
    //*(++iter) = 280;
    //*(iter--) = 280;
    //*(--iter) = 280;
}

// TEST(iterator_removals_inserts){
//     // emptyList.push_back(2);
//     // emptyList.push_back(3);
//     // emptyList.push_back(4);
//     List<int> emptyList;
//     emptyList.push_back(1);
//     emptyList.push_back(2);

//     List<int>::Iterator it = emptyList.begin();
//     ASSERT_TRUE(*it == 1);
//     //it = emptyList.insert(it, 1);
//     //ASSERT_TRUE(*it == 1);
//     it = emptyList.erase(it);
//     ASSERT_TRUE(*it == 2);
//     //cannot test removal without two or more items
//     //cannot test additions without one or more items

//     //so for the removals:
//     //two and larger size arrays
//     //remove from end
//     //remove from beginning
//     //remove from middle

//     //for the additions:
//     //add to end
//     //add to beginning
//     //add to middle

//     //Check all the data and make sure the
//     //list size is correct


// }

/*Hints for testing
TRIED THIS
List::operator= (Assignement Operator) Bug #1 
- Your tests fail to catch a bug in this function. 
Double check that you have tests for the assignment 
operator specifically, e.g. not something like List 
list2 = list; which uses the copy constructor. Assignment 
would require a separate line like list2 = list; after 
list2 has already been defined.


*/



TEST_MAIN()
