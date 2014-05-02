/*
 * Kruskal and Prim Algorithms
 *
 * Reference : http://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/ch4.zip
 */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

class UnionFind {
private:
    vi p, rank, setSize;
    int numSets;
public:
    UnionFind(int N) {
        setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i) {
        return ((p[i] == i) ? i : p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            numSets--;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
                p[y] = x; setSize[x] += setSize[y];
            } else {
                p[x] = y; setSize[y] += setSize[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
    int numDisjoinSets() {
        return numSets;
    }
    int sizeOfSet(int i) {
        return setSize[findSet(i)];
    }
};

vector< pair<int, ii> > EdgeList;
vector<vii> AdjList;
int V, E;

void input() {
    V = 5, E= 7;

    EdgeList.push_back(make_pair(4, ii(0, 1)));
    EdgeList.push_back(make_pair(4, ii(0, 2)));
    EdgeList.push_back(make_pair(6, ii(0, 3)));
    EdgeList.push_back(make_pair(6, ii(0, 4)));
    EdgeList.push_back(make_pair(2, ii(1, 2)));
    EdgeList.push_back(make_pair(8, ii(2, 3)));
    EdgeList.push_back(make_pair(9, ii(3, 4)));

    AdjList.assign(V, vii());
    for (int i = 0; i < E; i++) {
        int u = EdgeList[i].second.first;
        int v = EdgeList[i].second.second;
        int w = EdgeList[i].first;

        AdjList[u].push_back(ii(v, w));
        AdjList[v].push_back(ii(u, w));
    }
}

void test_kruskal() {
    sort(EdgeList.begin(), EdgeList.end());

    int mst_cost = 0;
    UnionFind UF(V);
    for (int i = 0; i < E; i++) {
        pair<int, ii> edge = EdgeList[i];
        if (!UF.isSameSet(edge.second.first, edge.second.second)) {
            mst_cost += edge.first;
            UF.unionSet(edge.second.first, edge.second.second);
        }
    }

    assert(mst_cost == 18);
}

vi taken;
priority_queue<ii> pq;

void prim_process(int vtx) {
    taken[vtx] = 1;
    for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
        ii v = AdjList[vtx][j];
        if (!taken[v.first]) {
            pq.push(ii(-v.second, -v.first));
        }
    }
}

void test_prim() {
    taken.assign(V, 0);
    prim_process(0);
    int mst_cost = 0;
    while (!pq.empty()) {
        int u, w;
        ii edge = pq.top(); pq.pop();
        u = -edge.second, w = -edge.first;
        if (!taken[u]) {
            mst_cost += w;
            prim_process(u);
        }
    }

    assert(mst_cost == 18);
}

int main() {
    input();

    // Kruskal Algorithm
    test_kruskal();

    // Prim Algorithm
    test_prim();

    return 0;
}
