#include <cstdio>
#include <map>
#include <cstring>
#include <string>
using namespace std;

int p[200010], rank[200010], set_size[200010];
map<string, int> name_map;

int uf_find(int i) {
	return p[i] == i ? i : p[i] = uf_find(p[i]);
}

int uf_union(int a, int b) {
	int pa = uf_find(a), pb = uf_find(b);
	if (pa != pb) {
		if (rank[a] < rank[b]) {
			p[pa] = pb;
			return set_size[pb] += set_size[pa];
		} else {
			if (rank[a] == rank[b])
				++rank[a];
			p[pb] = pa;
			return set_size[pa] += set_size[pb];
		}
	}
	return set_size[pa];
}

int main() {
	int cases;
	scanf("%d", &cases);
	while (cases--) {
		int n = 0, m;
		scanf("%d", &m);
		char a[30], b[30];
		name_map.clear();
		for (int i = 0; i < m; ++i) {
			scanf("%s %s", a, b);

			string as(a), bs(b);
			if (name_map.find(as) == name_map.end()) {
				name_map[as] = n;
				p[n] = n; rank[n] = 0; set_size[n] = 1;
				++n;
			}
			if (name_map.find(bs) == name_map.end()) {
				name_map[bs] = n;
				p[n] = n; rank[n] = 0; set_size[n] = 1;
				++n;
			}
			int ai = name_map[as], bi = name_map[bs];

			printf("%d\n", uf_union(ai, bi));
		}
	}
	return 0;
}
