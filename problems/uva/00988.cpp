#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > adj_list;
vector<int> dfs_num, sorted, num_paths;

void toposort(int u) {
    dfs_num[u] = 1;
    for (int j = 0; j < (int)adj_list[u].size(); ++j) {
        if (dfs_num[adj_list[u][j]] == -1)
            toposort(adj_list[u][j]);
    }
    sorted.push_back(u);
}

int main()
{
    int n;
    bool first = true;
    while (scanf("%d", &n) != EOF) {
        adj_list.assign(n, vector<int>());

        for (int i = 0; i < n; ++i) {
            int m;
            scanf("%d", &m);
            if (m == 0)
                continue;
            else {
                int temp;
                for (int j = 0; j < m; ++j) {
                    scanf("%d", &temp);
                    adj_list[i].push_back(temp);
                }
            }
        }
        dfs_num.assign(n, -1);
        sorted.clear();
        toposort(0);
        num_paths.assign(n, 0);
        num_paths[sorted.back()] = 1;

        for (int i = (int)sorted.size() - 1; i >= 0; --i) {
            int u = sorted[i];
            for (int j = 0; j < (int)adj_list[u].size(); ++j)
                num_paths[adj_list[u][j]] += num_paths[u];
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!adj_list[i].size())
                ans += num_paths[i];
        }
        if (first) {
            printf("%d\n", ans);
            first = false;
        } else
            printf("\n%d\n", ans);
    }
    return 0;
}
