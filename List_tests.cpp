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
        //std::cout << "At item #" << j << ", get " << *it << std::endl;
        ASSERT_EQUAL(*it, j);
    }

    //std::cout << "Test of prefilled list variable modifications passed" << std::endl;
}

//Copy constructor execution
// TEST(testing_empty_copy) {
//     //Checking consecuitve executions 
//     List<int> base_maker;
//     List<int> emptyList = base_maker;
//     ASSERT_TRUE(emptyList.empty());
//     ASSERT_TRUE(emptyList.empty());
//     //std::cout << "Consecutive test of copy empty passed" << std::endl;

//     ASSERT_TRUE(base_maker.empty());
//     for (int i = 0; i < 5; ++i) {
//         base_maker.push_back(i);
//     }
//     List<int> emptyList2 = base_maker;
//     ASSERT_FALSE(emptyList2.empty());
//     ASSERT_FALSE(emptyList2.empty());
//     //std::cout << "Test of copy empty pre and post filled passed" << std::endl;

//     int j = 0;
//     for (List<int>::Iterator it = emptyList2.begin(); it != emptyList2.end(); ++it, ++j) {
//         //std::cout << "At item #" << j << ", get " << *it << std::endl;
//         ASSERT_EQUAL(*it, j);
//     }

//     //std::cout << "Test of prefilled list variable modifications passed" << std::endl;
// }


// TEST(testing_size) {
//     List<int> emptyList;
//     ASSERT_EQUAL(emptyList.size(),0);

//     emptyList.push_front(10);
//     ASSERT_EQUAL(emptyList.size(),1);
// }

// TEST(testing_front){
//     List<int> emptyList;
//     ASSERT_EQUAL(emptyList.front(),nullptr);

//     emptyList.push_front(10);
//     ASSERT_EQUAL(emptyList.front(),10);
// }

// TEST(testing_back){
//     List<int> emptyList;
//     ASSERT_EQUAL(emptyList.back(),nullptr);

//     emptyList.push_back(10);
//     ASSERT_EQUAL(emptyList.back(),10);
// }

// TEST(testing_pushfront){
//     List<int> emptyList;

//     emptyList.push_front(10);
//     ASSERT_EQUAL(emptyList.front(),10);

//     emptyList.push_front(20);
//     ASSERT_EQUAL(emptyList.front(),20);
// }

// TEST(testing_pushback){
//     List<int> emptyList;

//     emptyList.push_back(10);
//     ASSERT_EQUAL(emptyList.back(),10);

//     emptyList.push_back(20);
//     ASSERT_EQUAL(emptyList.back(),20);
// }

// TEST(testing_popfront){
//     List<int> emptyList;
//     emptyList.push_front(10);
//     emptyList.push_front(20);
//     emptyList.pop_front();
//     ASSERT_EQUAL(emptyList.front(),10);
// }

// TEST(testing_popback){
//     List<int> emptyList;
//     emptyList.push_front(10);
//     emptyList.push_front(20);
//     emptyList.pop_back();
//     ASSERT_EQUAL(emptyList.front(),20);
// }

// TEST(default_iterator_constructor){
//     List<int> emptyList;
//     List<int>::Iterator empty;
    
//     emptyList.push_back(1);
//     emptyList.push_back(2);
//     emptyList.push_back(3);
//     emptyList.push_back(4);

// }

TEST_MAIN()
