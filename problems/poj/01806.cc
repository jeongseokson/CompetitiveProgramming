#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[12][25][25];
int b[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int m;
        scanf("%d", &m);
        memset(a[0], -1, sizeof(a[0]));
        a[0][m + 1][m + 1] = m;

        printf("Scenario #%d:\n", i);

        for (int j = 1; j <= m + 1; ++j) {
            memset(a[j], -1, sizeof(a[j]));
            printf("slice #%d:\n", j);
            for (int k = 1; k <= 2 * m + 1; k++) {
                for (int l = 1; l <= 2 * m + 1; l++) {
                    printf("%c", a[j - 1][k][l] == -1 ? '.' : a[j - 1][k][l] + '0');

                    if (a[j - 1][k][l] > 0) {
                        if (a[j - 1][k][l] == m) {
                            for (int o = 0; o < 4; o++) {
                                if (a[j - 1][k + b[o][0]][l + b[o][1]] == -1)
                                    a[j][k + b[o][0]][l + b[o][1]] = m;
                            }
                        }
                        a[j][k][l] = a[j - 1][k][l] - 1;
                    }
                }
                printf("\n");
            }
        }

        for (int j = m + 2; j <= 2 * m + 1; ++j) {
            printf("slice #%d:\n", j);
            int trans = 2 * m + 1 - j;
            for (int k = 1; k <= 2 * m + 1; k++) {
                for (int l = 1; l <= 2 * m + 1; l++)
                    printf("%c", a[trans][k][l] == -1 ? '.' : a[trans][k][l] + '0');
                printf("\n");
            }
        }

        printf("\n");
    }
    return 0;
}
