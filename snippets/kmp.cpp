/*
 * KMP string matching algorithm.
 *
 * Reference : http://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/ch6.zip
 */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>

using namespace std;

int n, m;
char T[1000], P[1000];
int kmp_pre[1000];

void input() {
    strcpy(T, "I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN");
    strcpy(P, "SEVENTY SEVEN");
    n = strlen(T);
    m = strlen(P);
}

void test_naive_matching() {
    int index = -1;

    for (int i = 0; i < n; i++) {
        bool found = true;
        for (int j = 0; j < m; j++) {
            if (T[i + j] != P[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            index = i;
            break;
        }
    }

    assert(index == 30);
}

void kmp_preprocess() {
    int i = 0, j = -1;
    kmp_pre[0] = -1;
    while (i < m) {
        while (P[i] != P[j] && j >= 0)
            j = kmp_pre[j];
        i++; j++;
        kmp_pre[i] = j;
    }
}

void kmp_search(vector<int> &indices) {
    int i = 0, j = 0;
    while (i < n) {
        while (T[i] != P[j] && j >= 0)
            j = kmp_pre[j];
        i++; j++;
        if (j == m)
            indices.push_back(i - m);
    }
}

void test_kmp() {
    vector<int> indices;

    kmp_preprocess();
    kmp_search(indices);

    int ans[] = {30};
    equal(indices.begin(), indices.end(), ans);
}

int main() {
    input();

    test_naive_matching();

    test_kmp();

    return 0;
}
