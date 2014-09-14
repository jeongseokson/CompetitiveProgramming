#include <cstdio>
#include <cstring>

char a[1000][1000], mark[1000][1000];
int count[5], max_r, max_c,
    b[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

void init() {
    memset(a[0], 1, max_c + 2);
    for (int i = 1; i <= max_r; i++) {
        memset(&a[i][1], 0, max_c * sizeof(char));
        a[i][0] = a[i][max_c +1] = 1;

        memset(&mark[i][1], 0, max_c * sizeof(char));
    }
    memset(a[max_r + 1], 1, (max_c + 2) * sizeof(int));

    memset(count, 0, sizeof count);
}

void solve_maze(int r, int c) {
    int dir = 0;
    while (r != max_r || c != 1 || mark[r][c] != 1) {
        --count[mark[r][c]];
        ++count[mark[r][c] + 1];
        ++mark[r][c];

        if (a[r + b[(dir + 3) % 4][0]][c + b[(dir + 3) % 4][1]] == 0)
            dir = (dir + 3) % 4;
        else {
            while (a[r + b[dir][0]][c + b[dir][1]] == 1)
                dir = (dir + 1) % 4;
        }

        r += b[dir][0]; c += b[dir][1];
    }
}

int main() {
    while (true) {
        scanf("%d %d\n", &max_r, &max_c);
        if (max_r == 0 && max_c == 0)
            break;

        init();
        for (int i = 1; i <= max_r; i++) {
            for (int j = 1; j <= max_c; j++) {
                char ch;
                scanf("%c", &ch);
                if (ch == '\n') {
                    j--;
                    continue;
                }
                a[i][j] = ch - '0';
                count[0] += 1 - a[i][j];
            }
        }

        solve_maze(max_r, 1);
        for(int i = 0; i < 5; i++) {
            printf("%3d", count[i]);
        }
        printf("\n");
    }

    return 0;
}
