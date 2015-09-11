#include <cstdio>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

int a[10];

int main() {
	int n;
	while (scanf("%d", &n), n > 0) {
		map<string, int> freq;
		int max_cnt = 0, same = 0;
		for (int i = 0; i < n; ++i) {
			char comb[20];
			for (int j = 0; j < 5; ++j)
				scanf("%d", a + j);
			sort(a, a + 5);
			for (int j = 0; j < 5; ++j)
				sprintf(comb + j * 3, "%03d", a[j]);

			string key(comb);
			if (freq.find(key) == freq.end())
				freq[key] = 1;
			else
				++freq[key];

			if (max_cnt == freq[key])
				++same;
			else if (max_cnt < freq[key]) {
				same = 1;
				max_cnt = freq[key];
			}
		}
		printf("%d\n", max_cnt * same);
	}
	return 0;
}
