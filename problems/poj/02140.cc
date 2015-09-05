#include <cstdio>

using namespace std;

int main() {
    int n, i;
    int ans = 0;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        int a;
        if (((i % 2) && !(n % i)) || (!(i % 2) && !((n - i / 2) % i))) {
            a = n / i + (1 - i) / 2;
        } else
            continue;

        if (a >= 1 && a + i - 1 <= n)
            ++ans;
    }

    printf("%d", ans);
    return 0;
}
