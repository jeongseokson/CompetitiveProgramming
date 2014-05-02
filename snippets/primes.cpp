/*
 * Prime number applications.
 *
 * Reference : http://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/ch5.zip
 */

#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) {
        if (bs[i]) {
            for (ll j = i * i; j<= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i);
        }
    }
}

bool isPrime(ll N) {
    if (N <= _sieve_size)
        return bs[N];
    for (int i = 0; i < (int)primes.size(); i++) {
        if (N % primes[i] == 0)
            return false;
    }
    return true;
}

vi primeFactors(ll N) {
    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while (N != 1 && (PF * PF <= N)) {
        while (N % PF == 0) {
            N /= PF;
            factors.push_back(PF);
        }
        PF = primes[++PF_idx];
    }
    if (N != 1)
        factors.push_back(N);
    return factors;
}

ll numPF(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
    while (N != 1 && (PF * PF <= N)) {
        while (N % PF == 0) {
            N /= PF; ans++;
        }
        PF = primes[++PF_idx];
    }
    if (N != 1)
        ans++;
    return ans;
}

ll numDiffPF(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
    while (N != 1 && (PF * PF <= N)) {
        if (N % PF == 0)
            ans++;
        while (N % PF == 0) {
            N /= PF;
        }
        PF = primes[++PF_idx];
    }
    if (N != 1)
        ans++;
    return ans;
}

ll sumPF(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
    while (N != 1 && (PF * PF <= N)) {
        while (N % PF == 0) {
            N /= PF;
            ans += PF;
        }
        PF = primes[++PF_idx];
    }
    if (N != 1)
        ans = N;
    return ans;
}

ll numDiv(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
    while (N != 1 && (PF * PF <= N)) {
        ll power = 0;
        while (N % PF == 0) {
            N /= PF; ++power;
        }
        ans *= (power + 1);
        PF = primes[++PF_idx];
    }
    if (N != 1)
        ans *= 2;
    return ans;
}

ll sumDiv(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
    while (N != 1 && (PF * PF <= N)) {
        ll power = 0;
        while (N % PF == 0) {
            N /= PF; ++power;
        }
        ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);
        PF = primes[++PF_idx];
    }
    if (N != 1)
        ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1);
    return ans;
}

// Count the number of relatively primes to N
ll EulerPhi(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = N;
    while (N != 1 && (PF * PF <= N)) {
        if (N % PF == 0)
            ans -= ans / PF;
        while (N % PF == 0) {
            N /= PF;
        }
        PF = primes[++PF_idx];
    }

    if (N != 1)
        ans -= ans / N;
    return ans;
}

int main() {
    // The Sieve of Eratosthenes
    sieve(1000000);

    // Prime check
    assert(isPrime(2147483647));
    assert(!isPrime(136117223861LL));

    // Prime factors
    vi res = primeFactors(2147483647);
    ll ans1[] = {2147483647};
    assert(equal(res.begin(), res.end(), ans1));
    res = primeFactors(136117223861LL);
    ll ans2[] = {104729, 1299709};
    assert(equal(res.begin(), res.end(), ans2));
    res = primeFactors(142391208960LL);
    ll ans3[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 5, 7, 7, 7, 7, 11, 13};
    assert(equal(res.begin(), res.end(), ans3));


    // Prime number applications
    assert(numPF(50) == 3);
    assert(numDiffPF(50) == 2);
    assert(sumPF(50) == 12);
    assert(numDiv(50) == 6);
    assert(sumDiv(50) == 93);
    assert(EulerPhi(50) == 20);
}
