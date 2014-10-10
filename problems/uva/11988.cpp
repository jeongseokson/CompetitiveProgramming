#include <cstdio>
#include <cstring>
#include <list>

#define MAX_LEN 100005

using namespace std;

char s[100010];
list<char*> linked_chars;

int main() {
    while (fgets(s, MAX_LEN, stdin) != NULL) {
        size_t len = strlen(s);
        if (s[len - 1] == '\n') {
            s[len - 1] = '\0';
            --len;
        }

        linked_chars.clear();
        if (s[0] != '[' && s[0] != ']')
            linked_chars.push_back(s);

        for (int i = 0; i < len; i++) {
            if (s[i] == '[') {
                linked_chars.push_front(s + i + 1);
                s[i] = '\0';
            } else if (s[i] == ']') {
                linked_chars.push_back(s + i + 1);
                s[i] = '\0';
            }
        }

        for (list<char*>::iterator it = linked_chars.begin();
                it != linked_chars.end(); it++)
            printf("%s", *it);
        printf("\n");
    }

    return 0;
}
