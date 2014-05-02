/*
 * SSSP and ASSP : Bellman-Ford, Dijkstra, Floyd-Warshall.
 *
 * Reference : http://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/ch4.zip
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>

#define INF 1000000000

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AdjList;
int V, E;

#define addEdge(u, v, w) AdjList[u].push_back(ii(v, w))
void input_negative_wight() {
    V = 5; E = 5;
    AdjList.assign(V, vii());

    addEdge(0, 1, 1); addEdge(0, 2, 10); addEdge(1, 3, 2); 
    addEdge(2, 3, -10); addEdge(3, 4, 3);
}

void input_negative_cycle() {
    V = 3; E = 3;
    AdjList.assign(V, vii());

    addEdge(0, 1, 1000); addEdge(1, 2, 15); addEdge(2, 1, -42);

}

void test_dijkstra() {
    int s = 0;
    vi dist(V, INF); dist[s] = 0;
    priority_queue< ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, s));

    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u])
            continue;
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (dist[v.first] > dist[u] + v.second) {
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }

    int ans[] = {0, 1, 10 , 0, 3};
    assert(equal(dist.begin(), dist.end(), ans));
}

void test_bellman_ford() {
    int s = 0;
    vi dist(V, INF); dist[s] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                dist[v.first] = min(dist[v.first], dist[u] + v.second);
            }
        }
    }

    bool has_negative_cycle = false;
    for (int u = 0; u < V; u++) {
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (dist[v.first] > dist[u] + v.second)
                has_negative_cycle = true;
        }
    }

    assert(has_negative_cycle);
}

int AdjMatrix[200][200];

void input_adj_matrix() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            AdjMatrix[i][j] = INF;
        }
        AdjMatrix[i][i] = 0;
    }

    for (int u = 0; u < V; u++) {
        for (int j = 0; j < AdjList[u].size(); j++) {
            AdjMatrix[u][AdjList[u][j].first] = AdjList[u][j].second;
        }
    }
}

void test_floyd_warshall() {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                AdjMatrix[i][j] = min(AdjMatrix[i][j],
                        AdjMatrix[i][k] + AdjMatrix[k][j]);
            }
        }
    }

    int ans[] = {0, 1, 10 , 0, 3};
    assert(equal(AdjMatrix[0], AdjMatrix[0] + V, ans));
}

int main () {
    input_negative_cycle();
    // Bellman-Ford Test
    test_bellman_ford();

    input_negative_wight();
    // Dijkstra Test
    test_dijkstra();

    input_adj_matrix();
    // Floyd-Warshall Test
    test_floyd_warshall();

    return 0;
}
