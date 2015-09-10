#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[100010];
int sum[100010];

int main() {
    int n, s;
    while(scanf("%d %d", &n, &s) != EOF) {
        memset(sum, 0, (n + 1) * sizeof(int));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            sum[i] += a[i];
            sum[i + 1] = sum[i];
        }

        int min_len = n + 1;
        for (int i = 1; i <= n; ++i) {
            int *p = lower_bound(sum + i, sum + n + 1, sum[i - 1] + s);
            if (sum[p - sum] - sum[i - 1] >= s)
                min_len = min(min_len, (int)(p - sum - i + 1));
        }

        printf("%d\n", min_len == n + 1 ? 0 : min_len);
    }

    return 0;
}
