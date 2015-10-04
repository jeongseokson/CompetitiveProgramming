#include <cstdio>
#include <cmath>

using namespace std;

int a[11][11];
void pascal(int n)
{
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                a[i][j] = 1;
            else
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
}

int main() {
	pascal(10);
	int cases;
	scanf("%d", &cases);
	while (cases--) {
		int r, s, x, y, w;
		scanf("%d %d %d %d %d", &r, &s, &x, &y, &w);
		double p = (double)(s - r + 1) / s, total = 0;
		for (int k = x; k <= y; ++k) {
			total += a[y][k] * pow(p, k) * pow(1 - p, y - k);
		}
		printf(total * w <= 1 ? "no\n" : "yes\n");
	}
	return 0;
}
