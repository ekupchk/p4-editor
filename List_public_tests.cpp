#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;


TEST(test_list_default_ctor) {
    List<int> empty_list;
    cout << "we checking fr fr " << endl;
    ASSERT_TRUE(empty_list.empty());
}

TEST(test_traversal) {
    cout << "------------------------" << endl;
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    int j = 0;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it, ++j) {
        cout << "At item #" << j << ", get " << *it << endl;
        ASSERT_EQUAL(*it, j);
    }
    ASSERT_EQUAL(j, list.size());
}

TEST_MAIN()
