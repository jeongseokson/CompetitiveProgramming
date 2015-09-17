#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

bool chk[35000];
int a[110];

static inline int pow2(int j) {
	int ret = 1;
	while (j--)
		ret *= 2;
	return ret;
}

static inline unsigned int num_of_bits(unsigned int i) {
	 i = i - ((i >> 1) & 0x55555555);
	 i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	 return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int main() {
	int cases;
	scanf("%d", &cases);
	while (cases--) {
		int p, n;
		scanf("%d", &p);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int num = 0;
			for (int j = p - 1; j >= 0; --j) {
				int k;
				scanf("%d", &k);
				num += pow2(j) * k;
			}
			a[i] = num;
		}

		int min_num_bit = p,
			pow2_p = pow2(p);
		for (int i = 0; i < pow2_p; ++i) {
			int j;
			memset(chk, 0, pow2_p);
			for (j = 0; j < n; ++j) {
				if (chk[i & a[j]])
					break;
				chk[i & a[j]] = true;
			}

			if (j == n)
				min_num_bit = min(min_num_bit, (int)num_of_bits(i));
		}
		printf("%d\n", min_num_bit);
	}
	return 0;
}
