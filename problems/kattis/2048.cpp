#include <cstdio>
#include <cstring>
using namespace std;

int a[6][6];
bool chk[6][6];
int main() {
	memset(a, -1, sizeof(a));
	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= 4; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	int d;
	scanf("%d", &d);
	if (d == 0) {
		for (int i = 1; i <= 4; ++i) {
			for (int j = 1; j <= 4; ++j) {
				if (a[i][j] == 0)
					continue;
				int r = i, c = j;
				while(a[r][c - 1] == 0) {
					c -= 1;
				}
				if (a[i][j] == a[r][c - 1] && !chk[r][c - 1]) {
					a[r][c - 1] += a[i][j];
					a[i][j] = 0;
					chk[r][c - 1] = true;
				} else {
					int t = a[i][j];
					a[i][j] = 0;
					a[r][c] = t;
				}
			}
		}
	} else if (d == 1) {
		for (int j = 1; j <= 4; ++j) {
			for (int i = 1; i <= 4; ++i) {
				if (a[i][j] == 0)
					continue;
				int r = i, c = j;
				while(a[r - 1][c] == 0) {
					r -= 1;
				}
				if (a[i][j] == a[r - 1][c] && !chk[r - 1][c]) {
					a[r - 1][c] += a[i][j];
					a[i][j] = 0;
					chk[r - 1][c] = true;
				} else {
					int t = a[i][j];
					a[i][j] = 0;
					a[r][c] = t;
				}
			}
		}
	} else if (d == 2) {
		for (int i = 1; i <= 4; ++i) {
			for (int j = 4; j >= 1; --j) {
				if (a[i][j] == 0)
					continue;
				int r = i, c = j;
				while(a[r][c + 1] == 0) {
					c += 1;
				}
				if (a[i][j] == a[r][c + 1] && !chk[r][c + 1]) {
					a[r][c + 1] += a[i][j];
					a[i][j] = 0;
					chk[r][c + 1] = true;
				} else {
					int t = a[i][j];
					a[i][j] = 0;
					a[r][c] = t;
				}
			}
		}
	} else {
		for (int j = 1; j <= 4; ++j) {
			for (int i = 4; i >= 1; --i) {
				if (a[i][j] == 0)
					continue;
				int r = i, c = j;
				while(a[r + 1][c] == 0) {
					r += 1;
				}
				if (a[i][j] == a[r + 1][c] && !chk[r + 1][c]) {
					a[r + 1][c] += a[i][j];
					a[i][j] = 0;
					chk[r + 1][c] = true;
				} else {
					int t = a[i][j];
					a[i][j] = 0;
					a[r][c] = t;
				}
			}
		}
	}

	for (int i = 1; i <= 4; ++i) {
		printf("%d", a[i][1]);
		for (int j = 2; j <= 4; ++j) {
			printf(" %d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
