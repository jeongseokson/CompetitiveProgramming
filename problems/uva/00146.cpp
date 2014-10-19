#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    char seq[60];

    while(scanf("%s", seq) != EOF && seq[0] != '#') {
        if (next_permutation(seq, seq + strlen(seq)))
            printf("%s\n", seq);
        else
            printf("No Successor\n");
    }

    return 0;
}
