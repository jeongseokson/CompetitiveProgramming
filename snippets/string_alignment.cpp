/*
 * Solving string alignment problem with DP technique.
 *
 * Reference : http://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/ch6.zip
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>

using namespace std;

char A[100], B[100];
int n, m;
int d[101][101];

void input() {
    strcpy(A, "ACAATCC");
    strcpy(B, "AGCATGC");
    n = strlen(A);
    m = strlen(B);
}

void test_string_alignment() {
    for (int i = 1; i <= n; i++)
        d[i][0] = -i;
    for (int j = 1; j <= m; j++)
        d[0][j] = -j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j] = d[i - 1][j - 1] + (A[i] == B[j] ? 2 : -1);
            d[i][j] = max(d[i][j], d[i - 1][j] - 1);
            d[i][j] = max(d[i][j], d[i][j - 1] - 1);
        }
    }
    
    assert(d[n][m] == 7);
}

int main() {
    input();

    test_string_alignment();
    return 0;
}
