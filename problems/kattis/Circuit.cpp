#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[45][2];
int n;
long long dp[45][900][900];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &a[i][0], &a[i][1]);
	}

	dp[0][a[0][0] + 450][a[0][1] + 450] = dp[0][450][450] = 1;
	for (int i = 1; i < n; ++i) {
		memcpy(dp[i], dp[i - 1], sizeof(dp[i]));
		for (int j = max(0, a[i][0]); j < min(900, 900 + a[i][0]); ++j) {
			for (int k = max(0, a[i][1]); k < min(900, 900 + a[i][1]); ++k) {
				dp[i][j][k] += dp[i - 1][j - a[i][0]][k - a[i][1]];
			}
		}
	}
	printf("%lld\n", dp[n - 1][450][450] - 1);
	return 0;
}
