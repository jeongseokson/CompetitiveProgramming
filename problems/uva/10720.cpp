#include <cstdio>
#include <queue>

using namespace std;

int main() {
    while (true) {
        int n, a[10010];
        scanf("%d", &n);

        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
            scanf("%d", a + i);

        priority_queue<int> pq(a, a + n);
        vector<int> temp;

        for (int i = 0; i < n; i++) {
            int max = pq.top();
            pq.pop();
            for (int j = 0; j < max; j++) {
                if (pq.empty() || pq.top() <= 0)
                    goto out;
                temp.push_back(pq.top() - 1);
                pq.pop();
            }
            for (int j = 0; j < max; j++) {
                pq.push(temp.back());
                temp.pop_back();
            }
        }

        printf("Possible\n");
        continue;
out:
        printf("Not possible\n");
    }

    return 0;
}
