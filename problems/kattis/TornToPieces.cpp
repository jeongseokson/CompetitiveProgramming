#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

typedef map<string, set<string> > AdjList;
AdjList adj_list;
#define add_edge(a, b) \
    adj_list[a].insert(b); \
    adj_list[b].insert(a)

string dst_str;
string ans[50];
map<string, bool> visit;
bool found;
int len;
void dfs(string u, int path_len) {
    ans[path_len] = u;
    visit[u] = true;
    if (u == dst_str) {
        found = true;
        len = path_len;
        return;
    } else {
        set<string> &s = adj_list[u];
		for (set<string>::iterator jt  = s.begin(); jt != s.end(); ++jt) {
            if (!visit[*jt])
                dfs(*jt, path_len + 1);
            if (found)
            	return;
        }
    }
    visit[u] = false;
}

int main() {
    int n;
    scanf("%d", &n);
    char src[25], dst[25];
    for (int i = 0; i < n; ++i) {
        char ch;
        scanf("%s%c", src, &ch);
        visit[src] = false;
        while (true) {
            scanf("%s%c", dst, &ch);
            add_edge(src, dst);
            add_edge(dst, src);
            if (ch == '\n')
                break;
        }
    }
    scanf("%s %s", src, dst);
    dst_str = string(dst);
    dfs(src, 0);
    if (found) {
        printf("%s", ans[0].c_str());
        for (int i = 1; i <= len; ++i)
            printf(" %s", ans[i].c_str());
    } else
        printf("no route found");
    printf("\n");
    return 0;
}
