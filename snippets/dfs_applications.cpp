/*
 * Graph DFS Applications.
 *
 * Reference : http://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/ch2.zip
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define DFS_WHITE -1
#define DFS_BLACK 1

vector<vii> AdjList;

vi dfs_num;
vi topoSort;
int V;

void dfs_toposort(int u) {
    dfs_num[u] = DFS_BLACK;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE)
            dfs_toposort(v.first);
    }
    topoSort.push_back(u);
}

void test_topological_sort() {
    int ans1[] = {0, 1, 2, 3, 4};
    int ans2[] = {6, 8, 7};

    dfs_num.assign(V, DFS_WHITE);
    dfs_toposort(0); 
    assert(equal(topoSort.rbegin(), topoSort.rend(), ans1));
    topoSort.clear();
    dfs_toposort(6); 
    assert(equal(topoSort.rbegin(), topoSort.rend(), ans2));
}

#define DFS_GRAY 2
vi dfs_parent;
vii back_edge;
vii cross_edge;

void graph_check(int u) {
    dfs_num[u] = DFS_GRAY;
    for (int j = 0; j < AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE) {
            dfs_parent[v.first] = u;
            graph_check(v.first);
        } else if (dfs_num[v.first] == DFS_GRAY) {
            if (v.first != dfs_parent[u])
                back_edge.push_back(ii(u, v.first));
        } else if (dfs_num[v.first] == DFS_BLACK) {
        }
    }
    dfs_num[u] = DFS_BLACK;
}

void test_dfs_tree_check() {
    ii back_edge_arr[] = {ii(3, 1)};
    dfs_parent.assign(V, -1);
    dfs_num.assign(V, DFS_WHITE);
    graph_check(0);

    assert(equal(back_edge.begin(), back_edge.end(), back_edge_arr));
}

#define addEdge(from, to, weight) AdjList[(from)].push_back(ii((to), (weight)))

void input() {
    V = 9;
    AdjList.assign(V, vii());

    addEdge(0, 1, 0);
    addEdge(1, 0, 0); addEdge(1, 2, 0); addEdge(1, 3, 0); 
    addEdge(2, 1, 0); addEdge(2, 3, 0);
    addEdge(3, 1, 0); addEdge(3, 2, 0); addEdge(3, 4, 0);
    addEdge(4, 3, 0);
    addEdge(6, 7, 0); addEdge(6, 8, 0);
    addEdge(7, 6, 0);
    addEdge(8, 6, 0); 
}

int main() {
    input();

    // Topological Sort
    test_topological_sort();
    
    // DFS Spanning Tree Edge Check
    test_dfs_tree_check();
    
    // Articulation Points & Bridges
    
    // Strongly Connected Components
}
