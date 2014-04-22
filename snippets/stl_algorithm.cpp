/*
 * Examples of libraries in STL algorithm.
 *
 * Reference : http://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/ch2.zip
 */

#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

typedef struct triple {
    int first;
    int second;
    int third;

    bool operator==(const triple& r) {
        return first == r.first && second == r.second && third == r.third;
    }
} triple;

bool test_cmp(triple a, triple b) {
    if (a.third != b.third)
        return a.third < b.third;
    else if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

void test_sorting() {
    int arr[] = {10, 7, 2, 15, 4};
    vector<int> v(arr, arr + 5);

    int arr_asc[] = {2, 4, 7, 10, 15};
    int arr_desc[] = {15, 10, 7, 4, 2};
    vector<int> v_asc(arr_asc, arr_asc + 5);
    vector<int> v_desc(arr_desc, arr_desc + 5);

    // sort descending with vector
    sort(v.rbegin(), v.rend());
    assert(equal(v.begin(), v.end(), v_desc.begin()));

    // sort descending with integer array
    sort(arr, arr + 5);
    reverse(arr, arr + 5);
    assert(equal(arr, arr + 5, arr_desc));

    // random shuffle
    random_shuffle(v.begin(), v.end());

    // partial sort
    partial_sort(v.begin(), v.begin() + 2, v.end());
    assert(equal(v.begin(), v.begin() + 2, v_asc.begin()));

    // multi-field sorting
    triple test[4] = { {1, 1, 10},
                       {2, 3, 60},
                       {3, 1, 20},
                       {4, 3, 60} };

    triple test_sorted[4] = { {1, 1, 10},
                              {3, 1, 20},
                              {2, 3, 60},
                              {4, 3, 60} };

    sort(test, test + 4, test_cmp);
    assert(equal(test, test + 4, test_sorted));

    // simple multi-field sorting
    typedef pair< int, pair< string, string > > state;

    state a = make_pair(10, make_pair("C", "Linux"));
    state b = make_pair(9, make_pair("JAVA", "Windows"));
    state c = make_pair(8, make_pair("Python", "MacOSX"));

    vector<state> test_v;
    test_v.push_back(a);
    test_v.push_back(b);
    test_v.push_back(c);

    vector<state> test_sorted_v;
    test_sorted_v.push_back(c);
    test_sorted_v.push_back(b);
    test_sorted_v.push_back(a);

    sort(test_v.begin(), test_v.end());
    assert(equal(test_v.begin(), test_v.begin() + 3, test_sorted_v.begin()));
}

void test_binary_search() {
    int *pos, arr[] = {10, 7, 2, 15, 4};
    sort(arr, arr + 5);
    vector<int> v(arr, arr+5);

    pos = lower_bound(arr, arr + 5, 7);
    assert(*pos == 7);
}

void test_next_permutation() {
    int arr[] = {10, 7, 2, 15, 4};
    sort(arr, arr + 5);
    vector<int> v(arr, arr+5);


    next_permutation(arr, arr + 5);
    next_permutation(arr, arr + 5);

    next_permutation(v.begin(), v.end());
    next_permutation(v.begin(), v.end());

    int expected[] = {2, 4, 10, 7, 15};
    assert(equal(arr, arr + 5, expected));
}

void test_min_max() {
    assert(min(7, 10) == 7);
    assert(max(7, 10) == 10);
}

int main() {
    // sorting
    test_sorting(); 

    // binary search
    test_binary_search();
  
    // generate permutation of set
    test_next_permutation();

    // min, max
    test_min_max();
  
    return 0;
}
