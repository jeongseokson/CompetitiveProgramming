#include <cstdio>
#include <cstring>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

struct char_pair {
    char original[25];
    char normalized[25];
};

bool char_pair_comparator(const char_pair& lhs, const char_pair& rhs) {
    return strcmp(lhs.normalized, rhs.normalized) < 0 ? true : false;
}

bool char_ptr_comparator(const char* lhs, const char* rhs) {
    return strcmp(lhs, rhs) < 0 ? true : false;
}

void normalize(char src[], char dst[]) {
    strcpy(dst, src);
    for (char *p = dst; *p; ++p)
        *p = tolower(*p);
    sort(dst, dst + strlen(dst));
}


int main() {
    char_pair s[1005];
    int num_words = 0;

    while (scanf("%s", s[num_words].original),
            strcmp(s[num_words].original, "#")) {
        normalize(s[num_words].original, s[num_words].normalized);
        ++num_words;
    }

    sort(s, s + num_words, char_pair_comparator);

    char* result[1005];
    int num_ananagram = 0;
    for (int i = 0; i < num_words; i++){
        if ((i == 0 || strcmp(s[i - 1].normalized, s[i].normalized))
                && (i == num_words - 1 ||
                    strcmp(s[i + 1].normalized, s[i].normalized))) {
            result[num_ananagram++] = (char *)&s[i].original;
        }
    }

    sort(result, result + num_ananagram, char_ptr_comparator);

    for (int i = 0; i < num_ananagram; i++) {
        printf("%s\n", result[i]);
    }

    return 0;
}
