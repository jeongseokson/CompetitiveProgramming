/*
 * Construct suffix array.
 *
 * Reference : http://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/ch6.zip
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>

#define MAX_N 100

using namespace std;

int n;
char T[MAX_N];
int sa[MAX_N], temp_sa[MAX_N];
int ra[MAX_N], temp_ra[MAX_N];

void input() {
    strcpy(T, "GATAGACA");
    n = (int)strlen(T);
}

bool cmp(int a, int b) {
    return strcmp(T + a, T + b) < 0;
}

void construct_sa_slow() {
    for (int i = 0; i < n; i++) {
        sa[i] = i;
    }
    sort(sa, sa + n, cmp);
}

void counting_sort(int k) {
    int i, sum, c[300], maxi = max(300, n);
    memset(c, 0, sizeof c);

    for (i = 0; i < n; i++)
        c[i + k < n ? ra[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }

    for (i = 0; i < n; i++)
        temp_sa[c[sa[i] + k < n ? ra[sa[i] + k] : 0]++] = sa[i];
    for (i = 0; i < n; i++)
        sa[i] = temp_sa[i];
}

void construct_sa() {
    int i, k , r;

    for (i = 0; i < n; i++) {
        ra[i] = T[i];
        sa[i] = i;
    }

    for (k = 1; k < n; k << 1) {
        counting_sort(k);
        counting_sort(0);
        temp_ra[sa[0]] = r = 0;
        for (i = 1; i < n; i++)
            temp_ra[sa[i]] =
                (ra[sa[i]] == ra[sa[i-1]] && ra[sa[i]+k] == ra[sa[i-1]+k]) ? r : ++r;

        for (i = 0; i < n; i++)
            ra[i] = temp_ra[i];
        if (ra[sa[n-1]] == n - 1)
            break;
    }
}

void test_construct_sa() {
    construct_sa_slow();

    int ans[] = {7, 5, 3, 1, 6, 4, 0, 2};
    assert(equal(sa, sa + n, ans));

    construct_sa();
    assert(equal(sa, sa + n, ans));
}

int main() {

    input();

    test_construct_sa();

    return 0;
}
