/*
 * Max Cardinality Bipartite Matching
 *
 * Reference : http://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/ch4.zip
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vector<vi> AdjList;
int V;
void input() {
    V = 5; // 1 ~ 4
    AdjList.assign(V, vi());
    AdjList[1].push_back(3); AdjList[1].push_back(4);
    AdjList[2].push_back(3);
}

vi owner, visited;
int alternate(int l) {
    if (visited[l])
        return 0;
    visited[l] = 1;
    for (int j = 0; j < (int)AdjList[l].size(); j++) {
        int r = AdjList[l][j];
        if (owner[r] == -1 || alternate(owner[r])) {
            owner[r] = l;
            return 1;
        }
    }

    return 0;
}

void test_mcbm() {
    int mcbm = 0, Vleft = 3; // 1 ~ 2
    owner.assign(V, -1);
    for (int l = 0; l < Vleft; l++) {
        visited.assign(Vleft, 0);
        mcbm += alternate(l);
    }

    assert(mcbm == 2);
}

int main() {
    input();

    // Max Cardinality Bipartite Matching
    test_mcbm();
}
