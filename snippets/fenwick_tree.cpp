/*
 * Fenwick Tree.
 *
 * Reference : http://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/ch2.zip
 */

#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

#define LSOne(S) ((S) & (-(S)))

typedef vector<int> vi;

class FenwickTree {
private:
    vi ft;

public:
    FenwickTree(int n) {
        ft.assign(n + 1, 0);
    }

    int rsq(int b) {
        int sum = 0;
        for (; b; b -= LSOne(b))
            sum += ft[b];
        return sum;
    }

    int rsq(int a, int b) {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    void adjust(int k, int v) {
        for (; k < (int)ft.size(); k += LSOne(k))
            ft[k] += v;
    }
};

int main() {
    FenwickTree ft(10);

    ft.adjust(2, 1);
    ft.adjust(4, 1);
    ft.adjust(5, 2);
    ft.adjust(6, 3);
    ft.adjust(7, 2);
    ft.adjust(8, 1);
    ft.adjust(9, 1);

    assert(ft.rsq(1, 1) == 0);
    assert(ft.rsq(1, 2) == 1);
    assert(ft.rsq(1, 6) == 7);
    assert(ft.rsq(1, 10) == 11);
    assert(ft.rsq(3, 6) == 6);

    ft.adjust(5, 2);
    assert(ft.rsq(1, 10) == 13);

    return 0;
}
