#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    scanf("%d\n", &n);

    map<string, int> countries;
    for (int i = 0; i < n; i++) {
        char country[80];
        scanf("%s %*80[^\n]\n", country);

        countries[country]++;
    }

    for (map<string, int>::iterator it = countries.begin(); \
            it != countries.end(); it++) {
        printf("%s %d\n", it->first.c_str(), it->second);
    }
    return 0;
}
