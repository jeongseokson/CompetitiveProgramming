/*
 * Floyd's Cycle-Finding Algorithm
 *
 * Reference : http://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/ch5.zip
 */

#include <cstdio>
#include <utility>
#include <cassert>

using namespace std;

typedef pair<int, int> ii;

int caseNo = 1, Z, I, M, L;

int f(int x) {
    return (Z * x + I) % M;
}

ii floydCycleFinding(int x0) {
    // 1st part: finding k*mu, hare's speed is 2x tortoise's
    int tortoise = f(x0), hare = f(f(x0));
    while (tortoise != hare) {
        tortoise = f(tortoise); hare = f(f(hare));
    }

    // 2nd part: finding mu, hare and tortoise move at the same speed
    int mu = 0; hare = x0;
    while (tortoise != hare) {
        tortoise = f(tortoise); hare = f(hare);
        mu++;
    }

    // 3rd part: finding lambda, hare moves, tortoise stays
    int lambda = 1; hare = f(tortoise);
    while (tortoise != hare) {
        hare = f(hare);
        lambda++;
    }

    return ii(mu, lambda);
}

int main() {
    Z = 7, I = 5, M = 12, L = 4;

    ii result = floydCycleFinding(L);
    // 4 9 8 1 0 5 4 9 8 1 0 5 ...
    assert(result.second == 6);
}
