/*
 * Sparse Table.
 *
 * Reference : https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/
 */

#include <cstdio>
#include <cassert>

using namespace std;

#define N 10

int a[] = {2, 4, 3, 1, 6, 7, 8, 9, 1, 7};
int m[N][N];

void preprocess() {
    for (int i = 0; i < N; ++i)
        m[i][0] = i;

    for (int j = 1; 1 << j <= N; ++j) {
        for (int i = 0; i + (1 << j) - 1 < N; ++i) {
            if (a[m[i][j - 1]] <= a[m[i + (1 << (j - 1))][j - 1]])
                m[i][j] = m[i][j - 1];
            else
                m[i][j] = m[i + (1 << (j - 1))][j - 1];
        }
    }
}

int rmq(int i, int j) {
    int len = j - i + 1, k = 0;
    while (len >>= 1)
        ++k;

    if (a[m[i][k]] <= a[m[j - (1 << k) + 1][k]])
        return m[i][k];
    else
        return m[j - (1 << k) + 1][k];
}

int main() {
    preprocess();

    assert(rmq(0, 9) == 3);
    assert(rmq(3, 7) == 3);
    assert(rmq(4, 4) == 4);
    assert(rmq(8, 9) == 8);
    assert(rmq(4, 8) == 8);

    return 0;
}
