#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector<int> a;
void print_lis(int pos, vector<int> &a, int *p) {
	int w = pos;
	if (w != -1) {
		print_lis(p[w], a, p);
		printf("%d\n", a[w]);
	}
}

int main() {
	int num, n = 0;
	while (scanf("%d", &num) != EOF) {
		a.push_back(num);
		++n;
	}

	int *lis = (int*)malloc(n * sizeof(int)),
		*lis_id = (int*)malloc(n * sizeof(int)),
		*p = (int*)malloc(n * sizeof(int));

	int lis_len = 0, lis_end = 0;
	for (size_t i = 0; i < a.size(); ++i) {
		int *w = lower_bound(lis, lis + lis_len, a[i]);
		*w = a[i];
		int pos = w - lis;
		lis_id[pos] = i;
		p[i] = pos ? lis_id[pos - 1] : -1;
		if (pos >= lis_len- 1)
			lis_end = i;
		if (pos == lis_len)
			++lis_len;
	}

	printf("%d\n-\n", lis_len);
	print_lis(lis_end, a, p);

	free(lis);
	free(lis_id);
	free(p);
	return 0;
}
