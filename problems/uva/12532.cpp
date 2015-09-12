#include <cstdio>
#include <cstring>
using namespace std;

int a[100010], ft[100010], ft_zero[100010];
int n;

static inline void ft_update(int *f, int i, int v) {
	while (i <= n) {
		f[i] += v;
		i += i & (-i);
	}
}

static inline int rsq_start(int *f, int i) {
	int r = 0;
	while (i) {
		r += f[i];
		i -= i & (-i);
	}
	return r;
}

static inline int rsq(int *f, int p, int q) {
	return rsq_start(f, q) - (!p ? 0 : rsq_start(f, p - 1));
}

int main() {
	int k;
	while (scanf("%d %d", &n, &k) != EOF) {
		for (int i = 1; i <= n; ++i)
			scanf("%d", a + i);

		memset(ft, 0, sizeof(int) * (n + 1));
		memset(ft_zero, 0, sizeof(int) * (n + 1));

		for (int i = 1; i <= n; ++i) {
			if (a[i] < 0)
				ft_update(ft, i, 1);
			else if (!a[i])
				ft_update(ft_zero, i, 1);
		}

		for (int i = 0; i < k; ++i) {
			char c;
			int p, q;
			scanf("\n%c %d %d", &c, &p, &q);
			if (c == 'C') {
				if (a[p] < 0 && q >= 0)
					ft_update(ft, p, -1);
				else if (a[p] >= 0 && q < 0)
					ft_update(ft, p, 1);

				if (!a[p] && q)
					ft_update(ft_zero, p, -1);
				else if (a[p] && !q)
					ft_update(ft_zero, p, 1);
				a[p] = q;
			} else {
				int z = rsq(ft_zero, p, q),
					r = rsq(ft, p, q);
				printf("%c", z ? '0' : (r % 2 ? '-' : '+'));
			}
		}
		printf("\n");
	}
	return 0;
}
