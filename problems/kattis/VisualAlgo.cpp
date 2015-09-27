#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000000
#define addEdge(u, v, w) adj_list[u].push_back(ii(v, w))

vector<vii> adj_list;
vector<vi> dag;
int V, E;
int ans;
int t, shortest;
vi dist, dfs_num, sorted, num_paths;

void dijkstra(int s) {
    dist.assign(V, INF); dist[s] = 0;
    priority_queue< ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, s));

    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u])
            continue;
        for (int j = 0; j < (int)adj_list[u].size(); j++) {
            ii v = adj_list[u][j];
            if (dist[v.first] > dist[u] + v.second) {
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
}

void construct_dag() {
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < (int)adj_list[i].size(); j++) {
            ii v = adj_list[i][j];
            if (dist[v.first] == dist[i] + v.second)
                dag[i].push_back(v.first);
        }
    }
}

void toposort(int u) {
    dfs_num[u] = 1;
    for (int j = 0; j < (int)dag[u].size(); ++j) {
        if (dfs_num[dag[u][j]] == -1)
            toposort(dag[u][j]);
    }
    sorted.push_back(u);
}

int main() {
	scanf("%d %d", &V, &E);
    adj_list.assign(V, vii());
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int s;
    scanf("%d %d", &s, &t);
    dijkstra(s);
    dag.assign(V, vi());
    construct_dag();
    dfs_num.assign(V, -1);
    sorted.clear();
    toposort(s);
    num_paths.assign(V, 0);
    num_paths[sorted.back()] = 1;

    for (int i = (int)sorted.size() - 1; i >= 0; --i) {
        int u = sorted[i];
        for (int j = 0; j < (int)dag[u].size(); ++j)
            num_paths[dag[u][j]] += num_paths[u];
    }

    printf("%d\n", num_paths[t]);

	return 0;
}
