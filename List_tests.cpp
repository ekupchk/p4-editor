#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

TEST(testing_empty) {
    List<int> emptyList;
    ASSERT_TRUE(emptyList.empty());
}

TEST(testing_size) {
    List<int> emptyList;
    ASSERT_EQUAL(emptyList.size(),0);

    emptyList.push_front(10);
    ASSERT_EQUAL(emptyList.size(),1);
}

TEST(testing_front){
    List<int> emptyList;
    ASSERT_EQUAL(emptyList.front(),nullptr);

    emptyList.push_front(10);
    ASSERT_EQUAL(emptyList.front(),10);
}

TEST(testing_back){
    List<int> emptyList;
    ASSERT_EQUAL(emptyList.back(),nullptr);

    emptyList.push_back(10);
    ASSERT_EQUAL(emptyList.back(),10);
}

TEST(testing_pushfront){
    List<int> emptyList;

    emptyList.push_front(10);
    ASSERT_EQUAL(emptyList.front(),10);

    emptyList.push_front(20);
    ASSERT_EQUAL(emptyList.front(),20);
}

TEST(testing_pushback){
    List<int> emptyList;

    emptyList.push_back(10);
    ASSERT_EQUAL(emptyList.back(),10);

    emptyList.push_back(20);
    ASSERT_EQUAL(emptyList.back(),20);
}

TEST(testing_popfront){
    List<int> emptyList;
    emptyList.push_front(10);
    emptyList.push_front(20);
    emptyList.pop_front();
    ASSERT_EQUAL(emptyList.front(),10);
}

TEST(testing_popback){
    List<int> emptyList;
    emptyList.push_front(10);
    emptyList.push_front(20);
    emptyList.pop_back();
    ASSERT_EQUAL(emptyList.front(),20);
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
