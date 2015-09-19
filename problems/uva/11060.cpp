#include <cstdio>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>

using namespace std;

map<string, int> drink_to_ind;
string ind_to_drink[120];
set<int> outgoing[120];
set<int> incoming[120];
priority_queue<int, vector<int>, greater<int> > q;

int main() {
	int n, m, cases = 0;
	while(scanf("%d", &n) != EOF) {
		char drink1[60];
		for (int i = 0; i < n; ++i) {
			scanf("%s", drink1);
			string d(drink1);
			drink_to_ind[d] = i;
			ind_to_drink[i] = d;
			outgoing[i].clear(); incoming[i].clear();
		}

		scanf("%d", &m);
		char drink2[60];
		for (int i = 0; i < m; ++i) {
			scanf("%s %s", drink1, drink2);
			int from = drink_to_ind[string(drink1)],
				to = drink_to_ind[string(drink2)];

			outgoing[from].insert(to);
			incoming[to].insert(from);
		}

		for (int i = 0; i < n; ++i)
			if (!incoming[i].size())
				q.push(i);

		printf("Case #%d: Dilbert should drink beverages in this order:", ++cases);

		while (!q.empty()) {
			int top = q.top();
			printf(" %s", ind_to_drink[top].c_str());
			q.pop();
			set<int> *o = &outgoing[top];
			for (set<int>::iterator it = o->begin(); it != o->end(); ++it) {
				incoming[*it].erase(top);
				if (!incoming[*it].size())
					q.push(*it);
			}
		}

		printf(".\n\n");
	}
	return 0;
}
