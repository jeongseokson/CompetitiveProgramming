#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        vi *a = new vi[1000010];

        int num;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &num);
            a[num].push_back(i);
        }

        int k, v;
        for (int j = 0; j < m; j++) {
            scanf("%d %d", &k, &v);
            if (a[v].size() < k)
                printf("0\n");
            else
                printf("%d\n", a[v][k - 1]);
        }

        delete[] a;
    }

    return 0;
}
