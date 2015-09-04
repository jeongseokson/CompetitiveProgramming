#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAX_N 620

char t[MAX_N], t1[MAX_N/2], t2[MAX_N/2];
int n;
int c[MAX_N];
int ra[MAX_N], temp_ra[MAX_N];
int sa[MAX_N], temp_sa[MAX_N];
int phi[MAX_N], plcp[MAX_N], lcp[MAX_N];

using namespace std;

void counting_sort(int k) {
    memset(c, 0, sizeof c);

    int maxi = -1;
    for (int i = 0; i < n; ++i) {
        if (i + k < n) {
            ++c[ra[i + k]];
            if (maxi < ra[i + k])
                maxi = ra[i + k];
        } else
            ++c[0];
    }

    int sum = 0;
    for (int i = 0; i <= maxi; ++i) {
        int temp = c[i];
        c[i] = sum;
        sum += temp;
    }

    for (int i = 0; i < n; ++i) {
        if (sa[i] + k < n)
            temp_sa[c[ra[sa[i] + k]]++] = sa[i];
        else
            temp_sa[c[0]++] = sa[i];
    }

    for (int i = 0; i < n; ++i) {
        sa[i] = temp_sa[i];
    }
}

void update_ra(int k) {
    int r = 0;
    temp_ra[sa[0]] = 0;
    for (int i = 1; i < n; ++i) {
        if (ra[sa[i]] == ra[sa[i - 1]] && ra[sa[i] + k] == ra[sa[i - 1] + k])
            temp_ra[sa[i]] = r;
        else
            temp_ra[sa[i]] = ++r;
    }

    for (int i = 0; i < n; ++i)
        ra[i] = temp_ra[i];
}

void construct_sa() {
    memset(ra, 0, sizeof ra);

    for (int i = 0; i < n; ++i){
        sa[i] = i;
        ra[i] = t[i] - '.';
    }

    for (int k = 1; k < n; k <<= 1) {
        counting_sort(k);
        counting_sort(0);
        update_ra(k);
    }
}

void construct_lcp() {
    phi[sa[0]] = -1;
    for (int i = 1; i < n; ++i) {
        phi[sa[i]] = sa[i - 1];
    }

    int l = 0;
    for (int i = 0; i < n; ++i) {
        if (phi[i] == -1) {
            plcp[i] = 0;
            continue;
        }
        while (t[i + l] == t[phi[i] + l])
            ++l;
        plcp[i] = l;
        l = max(l - 1, 0);
    }

    for (int i = 0; i < n; i++) {
        lcp[i] = plcp[sa[i]];
    }
}

void solve() {
    int max_lcs_len = 0,
        len_t1 = strlen(t1);

    for (int i = 2; i < n; i++) {
        if ((sa[i - 1] - len_t1) * (sa[i] - len_t1) < 0)
            max_lcs_len = max(max_lcs_len, lcp[i]);
    }

    if (max_lcs_len == 0)
        printf("No common sequence.\n");
    else {
        char *prev = NULL;
        for (int i = 2; i < n; i++) {
            if (max_lcs_len == lcp[i] &&
                    (sa[i - 1] - len_t1) * (sa[i] - len_t1) < 0) {
                if (prev == NULL || strncmp(prev, t + sa[i], max_lcs_len)) {
                    printf("%.*s\n", max_lcs_len, t + sa[i]);
                    prev = t + sa[i];
                }
            }
        }
    }
}

int main() {
    int first = 1;
    while (scanf("%s", t1) != EOF) {
        scanf("%s", t2);

        strcpy(t, t1);
        strcat(t, ".");
        strcat(t, t2);

        n = strlen(t);
        construct_sa();
        construct_lcp();

        if (!first) {
            printf("\n");
        }
        first = 0;

        solve();
    }

    return 0;
}
