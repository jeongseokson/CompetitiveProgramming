#include <cstdio>
#include <algorithm>

using namespace std;

int r_arr[50010], c_arr[50010];

int main() {
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        int r, c, f;

        scanf("%d %d %d", &r, &c, &f);
        for (int i = 0; i < f; ++i)
            scanf("%d %d", r_arr + i, c_arr + i);

        sort(r_arr, r_arr + f);
        sort(c_arr, c_arr + f);

        printf("(Street: %d, Avenue: %d)\n", r_arr[(f - 1)/2], c_arr[(f - 1)/2]);
    }

    return 0;
}
