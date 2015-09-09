#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    char line[200];
    while (fgets(line, 200, stdin) != NULL) {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';
        printf("%s\n", line);
        char *p = strtok(line, " ");
        int n = 0;
        int a[40];
        while (p != NULL) {
            a[n++] = atoi(p);
            p = strtok(NULL, " ");
        }

        int sorted[40];
        memcpy(sorted, a, sizeof(int) * n);
        sort(sorted, sorted + n);
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] != sorted[i]) {
                for (int j = 0; j < i; j++) {
                    if (a[j] == sorted[i] && j != 0) {
                        printf("%d ", n - j);
                        reverse(a, a + j + 1);
                        break;
                    }
                }
                printf("%d ", n - i);
                reverse(a, a + i + 1);
            }
        }
        printf("0\n");
    }
    return 0;
}
