#include <cstdio>
#include <cstring>
using namespace std;

#define SAYS "Simon says"
int main() {
	int n;
	scanf("%d\n", &n);
	char line[110];
	int len = strlen(SAYS);
	for (int i = 0; i < n; ++i) {
		fgets(line, 109, stdin);
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = 0;
		if (!strncmp(SAYS, line, len))
			printf("%s\n", line + len);
	}
	return 0;
}
