/*
 * Graph BFS Applications.
 *
 * Reference : http://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/ch4.zip
 */

#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cassert>

#define INF 1000000000 

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int V, E;
vector<vii> AdjList;

#define add_edge(a, b) \
    AdjList[a].push_back(ii(b, 0)); \
    AdjList[b].push_back(ii(a, 0))

void input() {
    V = 13; E = 16;
    AdjList.assign(V, vii());

    add_edge(0, 1); add_edge(1, 2); add_edge(2, 3);
    add_edge(0, 4); add_edge(1, 5); add_edge(2, 6);
    add_edge(3, 7); add_edge(5, 6); add_edge(4, 8);
    add_edge(8, 9); add_edge(5, 10); add_edge(6, 11);
    add_edge(7, 12); add_edge(9, 10); add_edge(10, 11);
    add_edge(11, 12);
}

vi p;
void get_path(int s, int u, vi &path) {
    if (u == s) {
        path.push_back(u);
        return;
    }
    get_path(s, p[u], path);
    path.push_back(u);
}

void test_bipartite_check() {
    int s = 5;

    vi dist(V, INF); dist[s] = 0;
    queue<int> q; q.push(s);
    p.assign(V, -1);

    bool isBipartite = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (dist[v.first] == INF) {
                dist[v.first] = dist[u] + 1;
                p[v.first] = u;
                q.push(v.first);
            } else if ((dist[v.first] % 2) == (dist[u] % 2)) {
                isBipartite = false;
            }
        }
    }

    int t = 7;
    vi path;
    get_path(s, t, path);
    int path_arr[] = {5, 1, 2, 3, 7};

    assert(equal(path.begin(), path.end(), path_arr));
    assert(!isBipartite);
}

int main() {
    input();

    // Bipartite Check
    test_bipartite_check();
}
