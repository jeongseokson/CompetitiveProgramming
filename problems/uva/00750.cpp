#include <cstdio>
#include <cstring>

int soln[10], total;
bool r_chk[17], diag1[35], diag2[35];
int r, c;

void n_queen(int q) {
    if (q == 0) {
        printf("%2d     ", ++total);
        for (int i = 0; i < 8; ++i)
            printf(" %d", soln[i] + 1);
        printf("\n");
    } else {
        int j = 8 - q;
        if (j == c) {
            soln[j] = r;
            n_queen(q - 1);
        } else {
            for (int i = 0; i < 8; ++i) {
                if (!r_chk[i] && !diag1[i - j + 7] && !diag2[i + j]) {
                    r_chk[i] = 1; diag1[i - j + 7] = 1; diag2[i + j] = 1;
                    soln[j] = i;
                    n_queen(q - 1);
                    r_chk[i] = 0; diag1[i - j + 7] = 0; diag2[i + j] = 0;
                }
            }
        }
    }
}

int main() {
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d", &r, &c);
        r--; c--;
        memset(r_chk, 0, sizeof(r_chk));
		memset(diag1, 0, sizeof(diag1));
		memset(diag2, 0, sizeof(diag2));
        r_chk[r] = 1; diag1[r - c + 7] = 1; diag2[r + c] = 1;
        total = 0;
        printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
        n_queen(8);
        if (cases > 0)
            printf("\n");
    }
}
