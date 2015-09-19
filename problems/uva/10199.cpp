#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

map<string, int> mapper;
string ind[110];
vector<int> a[110];
int dfs_num[110], dfs_low[110], dfs_parent[110];
bool art[110];
int dfs_root, root_children, dfs_num_cnt;

void find_art_point(int u) {
	dfs_low[u] = dfs_num[u] = dfs_num_cnt++;
	for (size_t j = 0; j < a[u].size(); ++j) {
		int v = a[u][j];
		if (dfs_num[v] == -1) {
			dfs_parent[v] = u;
			if (u == dfs_root)
				root_children++;
			find_art_point(v);
			if (dfs_low[v] >= dfs_num[u])
				art[u] = true;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if (v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main() {
	int n, cases = 0;
	bool first = true;
	while (scanf("%d", &n), n) {
		char str[40];
		for (int i = 0; i < n; ++i) {
			scanf("%s", str);
			string s(str);
			ind[i] = s;
			a[i].clear();
		}
		sort(ind, ind + n);
		for (int i = 0; i < n; ++i)
			mapper[ind[i]] = i;

		int m;
		scanf("%d", &m);
		char str2[40];
		for (int i = 0; i < m; ++i) {
			scanf("%s %s", str, str2);
			int node1 = mapper[string(str)],
				node2 = mapper[string(str2)];
			a[node1].push_back(node2);
			a[node2].push_back(node1);
		}

		memset(dfs_num, -1, sizeof(int) * n);
		memset(dfs_parent, -1, sizeof(int) * n);
		memset(dfs_low, 0, sizeof(int) * n);
		memset(art, 0, sizeof(bool) * n);
		dfs_num_cnt = 0;
		for (int i = 0; i < n; ++i) {
			dfs_root = i; root_children = 0;
			if (dfs_num[i] == -1) {
				find_art_point(i);
				art[dfs_root] = (root_children > 1);
			}
		}

		int ans = 0;
		for (int i = 0; i < n; ++i)
			if (art[i])
				++ans;

		if (!first)
			printf("\n");
		first = false;
		printf("City map #%d: %d camera(s) found\n", ++cases, ans);
		for (int i = 0; i < n; ++i)
			if (art[i])
				printf("%s\n", ind[i].c_str());

	}
	return 0;
}
