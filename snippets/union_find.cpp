/*
 * Union and Find.
 *
 * Reference : http://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/ch2.zip
 */

#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

typedef vector<int> vi;

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

int main() {
    UnionFind UF(5); 
    assert(UF.numDisjoinSets() == 5);
    UF.unionSet(0, 1);
    assert(UF.numDisjoinSets() == 4);
    UF.unionSet(2, 3);
    assert(UF.numDisjoinSets() == 3);
    UF.unionSet(4, 3);
    // {0, 1} {2, 3, 4}
    assert(UF.numDisjoinSets() == 2);
    
    // isSameSet
    assert(!UF.isSameSet(0, 3));
    assert(UF.isSameSet(4, 3));

    // findSet
    assert(UF.findSet(1) == 1);
    assert(UF.findSet(4) == 3);

    // sizeOfSet
    assert(UF.sizeOfSet(1) == 2);
    assert(UF.sizeOfSet(3) == 3);

    UF.unionSet(0, 3);
    assert(UF.numDisjoinSets() == 1);
}
