#include <cstdio>
#include <set>
#include <functional>
#include <vector>

using namespace std;

int main() {
    int cases;

    scanf("%d", &cases);
    while (cases--) {
        int b, sg, sb, temp;
        multiset< int, greater<int> > green, blue;
        vector<int> survivors;

        scanf("%d %d %d", &b, &sg, &sb);
        for (int i = 0; i < sg; i++)
            scanf("%d", &temp), green.insert(temp);
        for (int i = 0; i < sb; i++)
            scanf("%d", &temp), blue.insert(temp);

        while (!green.empty() && !blue.empty()) {
            for (int i = 0; i < b && !green.empty() && !blue.empty(); i++) {
                survivors.push_back(*green.begin() - *blue.begin());
                green.erase(green.begin()); blue.erase(blue.begin());
            }
            for (int i = 0; i < survivors.size(); i++) {
                if (survivors[i] < 0)
                    blue.insert(-survivors[i]);
                else if (survivors[i] > 0)
                    green.insert(survivors[i]);
            }
            survivors.clear();
        }

        if (green.empty() && blue.empty())
            printf("green and blue died\n");
        else {
            multiset<int, greater<int> > *winner;

            if (green.empty()) {
                printf("blue wins\n");
                winner = &blue;
            } else if (blue.empty()) {
                printf("green wins\n");
                winner = &green;
            }

            for (multiset<int, greater<int> >::iterator it = winner->begin();
                    it != winner->end(); it++) {
                printf("%d\n", *it);
            }
        }

        if (cases)
            printf("\n");
    }

    return 0;
}
