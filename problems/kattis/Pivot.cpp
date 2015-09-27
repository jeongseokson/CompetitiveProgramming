#include <cstdio>
using namespace std;

int a[100010], min_a[100010], max_a[100010];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	int max = a[0];
	max_a[0] = a[0];
	for (int i = 1; i < n; ++i) {
		if (a[i] > max)
			max = a[i];
		max_a[i] = max;
	}
	int min = a[n - 1];
	min_a[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		if (a[i] < min)
			min = a[i];
		min_a[i] = min;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == min_a[i] && a[i] == max_a[i])
			++ans;
	}
	printf("%d\n", ans);
	return 0;
}
