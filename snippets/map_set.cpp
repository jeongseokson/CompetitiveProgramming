/*
 * Map and Set examples. (Balanced Binary Search Tree)
 *
 * Reference : http://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/ch2.zip
 */

#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <cassert>

using namespace std;

void test_map() {
    map<string, int> mapper;

    mapper["john"] = 78;
    mapper["billy"] = 69;
    mapper["andy"] = 80;
    mapper["steven"] = 77;
    mapper["felix"] = 82;
    mapper["grace"] = 75;
    mapper["martin"] = 81;

    assert(mapper["grace"] == 75);

    map<string, int>::iterator it1 = mapper.lower_bound("f");
    string s1 = it1->first;
    assert(!s1.compare("felix")); 

    map<string, int>::iterator it2 = mapper.upper_bound("g");
    string s2 = it2->first;
    assert(!s2.compare("grace")); 
}

void test_set() {
    set<int> used_values;

    used_values.insert(78);
    used_values.insert(69);
    used_values.insert(80);
    used_values.insert(77);
    used_values.insert(82);
    used_values.insert(75);
    used_values.insert(81);

    assert(*used_values.find(77) == 77);

    set<int>::iterator it1 = used_values.lower_bound(78);
    assert(*it1 == 78);

    assert(used_values.find(79) == used_values.end());
}

int main() {
    // map
    test_map();

    // set
    test_set();

    return 0;
}
