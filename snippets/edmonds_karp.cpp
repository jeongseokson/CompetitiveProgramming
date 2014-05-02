/*
 * Edmonds Karp's algorithm (Maximum Flow)
 *
 * Reference : http://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/ch4.zip
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cassert>

#define MAX_V 40
#define INF 1000000000

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int V;

int res[MAX_V][MAX_V];
vi p;

void input_adj_matrix() {
    V = 4;
    
    memset(res, 0, sizeof res);
    res[0][2] = 70; res[0][3] = 30;
    res[1][2] = 25; res[1][3] = 70;
    res[2][0] = 70; res[2][3] = 5; res[2][1] = 25;
    res[3][0] = 30; res[3][2] = 5; res[3][1] = 70;
}

int f;
void augment(int v, int s, int minEdge) {
    if (v == s) {
        f = minEdge;
        return;
    } else if (p[v] != -1) {
        augment(p[v], s, min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

void test_edmond_karp_with_adj_matrix() {
    int s = 0, t = 1, mf = 0;
    while (1) {
        f = 0;

        vi dist(MAX_V, INF); dist[s] = 0;
        queue<int> q; q.push(s);

        p.assign(MAX_V, -1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t)
                break;
            for (int v = 0; v < MAX_V; v++) {
                if (res[u][v] > 0 && dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v); p[v] = u;
                }
            }
        }
        augment(t, s, INF);
        if (f == 0) {
            break;
        }
        mf += f;
    }

    assert(mf == 60);
}

vector<vi> AdjList;

void input_adj_list() {
    int s = 0, t = 1, mf = 0;

    input_adj_matrix();
    AdjList.assign(V, vi());
    for (int i = 0; i < V; i++) {
        for (int j = 0 ; j < V; j++) {
            if (res[i][j] > 0)
                AdjList[i].push_back(j);
        }
    }
}

void test_edmond_karp_with_adj_list() {
    int s = 0, t = 1, mf = 0;
    while (1) {
        f = 0;

        vi dist(MAX_V, INF); dist[s] = 0;
        queue<int> q; q.push(s);

        p.assign(MAX_V, -1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t)
                break;
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (res[u][v] > 0 && dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v); p[v] = u;
                }
            }
        }
        augment(t, s, INF);
        if (f == 0) {
            break;
        }
        mf += f;
    }

    assert(mf == 60);
}

int main() {
    input_adj_matrix();
    test_edmond_karp_with_adj_matrix();

    input_adj_list();
    test_edmond_karp_with_adj_list();

    return 0;
}
