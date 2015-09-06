#include "cstdio"

using namespace std;

int n;
char a[120][120];
int b[12000][2];
int b_len;

#define diff_sq(a, b) (((a) - (b)) * ((a) - (b)))

static inline bool in_the_grid(int r, int c) {
    return (r >= 0) && (r < n) && (c >= 0) && (c < n);
}

static inline bool square_exist(int r1, int c1, int r2, int c2) {
    int det_r = r2 - r1,
        det_c = c2 - c1;

    return in_the_grid(r2 + det_c, c2 - det_r) &&
        in_the_grid(r2 + det_c - det_r, c2 - det_r - det_c) &&
        (a[r2 + det_c][c2 - det_r] == 'J'||
         a[r2 + det_c - det_r][c2 - det_r - det_c] == 'J') &&
        (a[r2 + det_c][c2 - det_r] != 'B' &&
         a[r2 + det_c - det_r][c2 - det_r - det_c] != 'B');
}

int main(int argc, char *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %c", &a[i][j]);
            if (a[i][j] == 'J') {
                b[b_len][0] = i;
                b[b_len++][1] = j;
            }
        }
    }

    int max = 0;
    for (int i = 0; i < b_len; ++i) {
        for (int j = 0; j < b_len; ++j) {
            if (i == j)
                continue;
            int r1 = b[i][0], c1 = b[i][1],
                r2 = b[j][0], c2 = b[j][1];
            int area = diff_sq(r1, r2) + diff_sq(c1, c2);
            if (max < area) {
                if (square_exist(r1, c1, r2, c2))
                    max = area;
            }
        }
    }

    printf("%d", max);

    return 0;
}
