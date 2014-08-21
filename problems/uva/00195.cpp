#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>

using namespace std;

bool char_comparator(char a, char b) {
    if (a - b == 32 || b - a == 32) {
        return a < b;
    } else {
        return tolower(a) < tolower(b);
    }
}

int main() {
    int n;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        char s[1000];
        scanf("%s", s);
        
        sort(s, s + strlen(s), char_comparator);
        do {
            printf("%s\n", s);
        } while (next_permutation(s, s + strlen(s), char_comparator));
    }
    return 0;
}
