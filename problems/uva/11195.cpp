#include <cstdio>
#include <cstring>
using namespace std;

bool a[17][17];
bool c_chk[17], diag1[35], diag2[35];
int n;

int n_queen(int q) {
	if (q == 0)
		return 1;
	else {
		int total = 0,
			i = n - q;
		for (int j = 0; j < n; ++j) {
			if (!c_chk[j] && !diag1[i - j + n - 1] && !diag2[i + j] && !a[i][j]) {
				a[i][j] = 1; c_chk[j] = 1; diag1[i - j + n - 1] = 1; diag2[i + j] = 1;
				total += n_queen(q - 1);
				a[i][j] = 0; c_chk[j] = 0; diag1[i - j + n - 1] = 0; diag2[i + j] = 0;
			}
		}

		return total;
	}
}

int main() {
	int cases = 0;
	while (scanf("%d", &n), n != 0) {
		memset(a, 0, sizeof(a));
		memset(c_chk, 0, sizeof(c_chk));
		memset(diag1, 0, sizeof(diag1));
		memset(diag2, 0, sizeof(diag2));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n ; ++j) {
				char c;
				scanf("\n%c", &c);
				if (c == '*')
					a[i][j] = 1;
			}
		}

		printf("Case %d: %d\n", ++cases, n_queen(n));
	}
	return 0;
}
