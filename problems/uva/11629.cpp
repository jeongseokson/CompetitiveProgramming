#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

map<string, int> mapper;

int main() {
	int p, q;
	scanf("%d %d", &p, &q);

	char party[30];
	char percent[10];
	for (int i = 0; i < p; ++i) {
		scanf("%s %s\n", party, percent);
		for (int j = 0; j < strlen(percent); ++j) {
			if (percent[j] == '.') {
				percent[j] = percent[j + 1];
				percent[j + 1] = '\0';
			}
		}
		mapper[party] = atoi(percent);
	}

	char line[2000];
	for (int i = 1; i <= q; ++i) {
		fgets(line, 2000, stdin);

		char *ptr = strtok(line, "+ ");
		int sum = 0;
		bool result = false;
		while (ptr != NULL) {
			if (!strcmp(ptr, ">")) {
				ptr = strtok(NULL, "+ ");
				result = sum > atoi(ptr) * 10;
			} else if (!strcmp(ptr, "<")) {
				ptr = strtok(NULL, "+ ");
				result = sum < atoi(ptr) * 10;
			} else if (!strcmp(ptr, ">=")) {
				ptr = strtok(NULL, "+ ");
				result = sum >= atoi(ptr) * 10;
			} else if (!strcmp(ptr, "<=")) {
				ptr = strtok(NULL, "+ ");
				result = sum <= atoi(ptr) * 10;
			} else if (!strcmp(ptr, "=")) {
				ptr = strtok(NULL, "+ ");
				result = sum == atoi(ptr) * 10;
			} else {
				int t = mapper[string(ptr)];
				sum += t;
			}
			ptr = strtok(NULL, "+ ");
		}
		printf("Guess #%d was %scorrect.\n", i, result ? "" : "in");
	}
	return 0;
}
