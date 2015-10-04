#include <cstdio>
#include <cstring>
using namespace std;
char a[110][110];
int find_pow(int num) {
	for (int i = 1; i <= 101; ++i) {
		if (i * i >= num)
			return i;
	}
	return 0;
}

void clock_wise(int n) {
	for(int i = 0; i < n / 2; i++) {
	   for(int j = 0; j < (n + 1) / 2; j++) {
		   int t = a[i][j];
		   a[i][j] = a[n - j - 1][i];
		   a[n - j - 1][i] = a[n - i - 1][n - j - 1];
		   a[n - i - 1][n - j - 1] = a[j][n - i - 1];
		   a[j][n - i - 1] = t;
	   }
	}
}
int main() {
	int cases;
	scanf("%d", &cases);
	char line[10010];
	while (cases--) {
		scanf("%s", line);
		int len = strlen(line);
		int side = find_pow(len);
		for (int i = 0; i < side; ++i) {
			for (int j = 0; j < side; ++j) {
				int ind = i * side + j;
				char ch = ind >= len ? '*' : line[ind];
				a[i][j] = ch;
			}
		}
		clock_wise(side);
		for (int i = 0; i < side; ++i) {
			for (int j = 0; j < side; ++j) {
				if (a[i][j] != '*')
					printf("%c", a[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
