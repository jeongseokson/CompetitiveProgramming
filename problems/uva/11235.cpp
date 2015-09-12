#include <cstdio>
#include <map>
using namespace std;

int a[100010], f[100010];
int m[100010][40];
int n;
map<int, int> freq;
map<int, pair<int, int> > boundary;

static inline int pfreq(int i, int x, int y) {
	int s = boundary[a[i]].first,
		e = boundary[a[i]].second,
		ret = f[i];

	if (s < x)
		ret -= (x - s);
	if (e > y)
		ret -= (e - y);

	return ret;
}

void preprocess() {
	for (int i = 0; i < n; ++i)
		m[i][0] = i;
	for (int j = 1; 1 << j <= n; ++j) {
		for (int i = 0; i + (1 << j) - 1 < n; ++i) {
			if (f[m[i][j - 1]] >= f[m[i + (1 << (j - 1))][j - 1]])
				m[i][j] = m[i][j - 1];
			else
				m[i][j] = m[i + (1 << (j -1))][j - 1];
		}
	}
}

static inline int rmq(int i, int j) {
	int len = j - i + 1, k = 0;
	if (len <= 0)
		return -1;

	while (len >>= 1)
		++k;

	if (f[m[i][k]] >= f[m[j - (1 << k) + 1][k]])
		return m[i][k];
	else
		return m[j - (1 << k) + 1][k];
}

int main() {
	while (scanf("%d", &n), n != 0) {
		int nq;
		scanf("%d", &nq);

		freq.clear();
		boundary.clear();

		int start = 0;
		scanf("%d", a);
		freq[a[0]] = 1;
		for (int i = 1; i < n; ++i) {
			scanf("%d", a + i);
			if (freq.find(a[i]) == freq.end()) {
				freq[a[i]] = 1;
				boundary[a[i - 1]] = make_pair(start, i - 1);
				start = i;
			} else {
				++freq[a[i]];
			}
		}
		boundary[a[n - 1]] = make_pair(start, n - 1);
		for (int i = 0; i < n; ++i)
			f[i] = freq[a[i]];
		preprocess();

		for (int i = 0; i < nq; ++i) {
			int s, e, fs = 0, fe = 0;
			scanf("%d %d", &s, &e);

			int ns = --s, ne = --e;
			if (boundary[a[s]].first < s) {
				fs = pfreq(s, s, e);
				ns = boundary[a[s]].second + 1;
			}
			if (boundary[a[e]].second > e) {
				fe = pfreq(e, s, e);
				ne = boundary[a[e]].first - 1;
			}

			int temp1 = fs > fe ? fs : fe,
				temp2 = rmq(ns, ne);
			temp2 = temp2 < 0 ? 0 : f[temp2];
			printf("%d\n", temp1 > temp2 ? temp1 : temp2);
		}
	}
	return 0;
}
