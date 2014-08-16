#include <cstdio>
#include <cstring>
#include <vector>

#define N 70000
#define M 3501

using namespace std;

int main() {
    bool prime[N];
    int prime_arr[N], prime_num = 0;

    for (int i = 2; i < N / 2; i++) {
        if (!prime[i]) {
            prime_arr[prime_num++] = i;
            if (prime_num == M)
                break;
            int k = i * 2;
            while (k < N) {
                prime[k] = 1;
                k += i;
            }
        }
    }

    vector<int> people;
    int n;
    while (scanf("%d", &n), n != 0) {
        people.clear();
        int pos = 0;
        for (int i = 1; i <= n; i++)
            people.push_back(i);

        for (int i = 0; i < n - 1; i++) {
            pos = (pos + prime_arr[i] - 1) % (n - i);
            people.erase(people.begin() + pos);
        }

        printf("%d\n", people.back());
    }

    return 0;
}
