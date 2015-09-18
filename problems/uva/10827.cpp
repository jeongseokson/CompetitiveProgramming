#include <cstdio>
#include <algorithm>
using namespace std;

int a[80][80];
int rsum[80][160];
int csum[160][80];
int n;

int find_1d_array_max_sum(int i, int j) {
	int max_sum = 0;
	for (int l = 0; l < n; ++l) {
		int sub_max_sum_row = 0, sub_max_sum_col = 0;
		for (int k = 0; k < n; ++k) {
			sub_max_sum_row += rsum[(l + k) % n][j] - (i ? rsum[(l + k) % n][i - 1] : 0);
			if (sub_max_sum_row < 0)
				sub_max_sum_row = 0;
			sub_max_sum_col += csum[j][(l + k) % n] - (i ? csum[i - 1][(l + k) % n] : 0);
			if (sub_max_sum_col < 0)
				sub_max_sum_col = 0;
			max_sum = max(max(max_sum, sub_max_sum_row), sub_max_sum_col);
		}
	}

	return max_sum;
}

int main() {
	int cases;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		for (int i = 0; i < n; ++i) {
			rsum[i][0] = a[i][0];
			csum[0][i] = a[0][i];
			for (int j = 1; j < 2 * n - 1; ++j) {
				rsum[i][j] = rsum[i][j - 1] + a[i][j % n];
				csum[j][i] = csum[j - 1][i] + a[j % n][i];
			}
		}
		int max_sum = 0;
		for (int i = 0; i < 2 * n - 1; ++i) {
			for (int j = i; j < min(2 * n - 1, i + n); ++j) {
				max_sum = max(max_sum, find_1d_array_max_sum(i, j));
			}
		}
		printf("%d\n", max_sum);
	}
	return 0;
}
