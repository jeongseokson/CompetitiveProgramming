#include <cstdio>
#include <vector>
#include <bitset>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi primes;
bitset<10000010> bs;
ll _sieve_size;

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

map<unsigned int, unsigned int> pfCount;
map<unsigned int, unsigned int> pfBCount;

unsigned int digits(int n, int b) {
	double log_sum = 0;
	for (int i = 2; i <= n; ++i)
		log_sum += log((double)i);
	log_sum /= log((double)b);

	return (unsigned int)(log_sum + 1e-5) + 1;
}

unsigned int zeros(int n, int b) {
	pfCount.clear(); pfBCount.clear();
	for (int i = 1; i <= n; ++i) {
		vi nPf = primeFactors(i);
		for (int j = 0; j < (int)nPf.size(); ++j)
			++pfCount[nPf[j]];
	}
	vi bPf = primeFactors(b);
	for (int i = 0; i < (int)bPf.size(); ++i)
		++pfBCount[bPf[i]];

	unsigned int min = 2147483647;
	for (map<unsigned int, unsigned int>::iterator it = pfBCount.begin(); it != pfBCount.end(); ++it) {
		if (min > pfCount[it->first] / it->second)
			min = pfCount[it->first] / it->second;
	}

	return min;
}

int main() {
	int n, b;
	sieve(2097152);

	while (scanf("%d %d", &n, &b) != EOF) {
		unsigned int d = digits(n, b);
		unsigned int z = zeros(n, b);

		printf("%u %u\n", z, d);
	}
	return 0;
}
