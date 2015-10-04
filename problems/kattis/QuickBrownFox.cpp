#include <cstdio>
#include <cstring>
using namespace std;

bool chk[300];
int main() {
	int n;
	scanf("%d\n", &n);
	char line[110];
	for (int i = 0; i < n; ++i) {
		fgets(line, 109, stdin);
		memset(chk, 0, 300);
		for (int j = 0; j < (int)strlen(line); ++j) {
			char ch = line[j];
			ch = ch >= 'A'  && ch <= 'Z' ? ch + 32 : ch;
			chk[(int)ch] = true;
		}
		bool ispanam = true;
		for (char ci = 'a'; ci <= 'z'; ++ci) {
			if (!chk[(int)ci]) {
				ispanam = false;
				break;
			}
		}
		if (ispanam)
			printf("pangram\n");
		else {
			printf("missing ");
			for (char ci = 'a'; ci <= 'z'; ++ci) {
				if (!chk[(int)ci])
					printf("%c", ci);
			}
			printf("\n");
		}
	}
	return 0;
}
