#include <cstdio>
#include <cstring>
using namespace std;

int c[110];

int main() {
    while (true) {
        int n;
        scanf("%d", &n);
        if (!n)
            break;

        memset(c, 0, sizeof(c));
        while (n--) {
            int t;
            scanf("%d", &t);
            ++c[t];
        }

        bool first = true;
        for (int i = 1; i < 100; ++i) {
            for (int j = 0; j < c[i]; ++j) {
                if (first) {
                    printf("%d", i);
                    first = false;
                } else {
                    printf(" %d", i);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
