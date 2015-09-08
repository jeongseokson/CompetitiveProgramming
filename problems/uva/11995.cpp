#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        stack<int> st;
        queue<int> q;
        priority_queue<int> pq;

        bool can_stack = true, can_queue = true, can_pq = true;
        for (int i = 0; i < n; i++) {
            int t, m1, m2;
            scanf("%d %d", &t, &m1);
            if (t == 1) {
                st.push(m1);
                q.push(m1);
                pq.push(m1);
            } else {
                if (st.empty() || (m2 = st.top(), m2 != m1))
                    can_stack = false;
                else
                    st.pop();
                if (q.empty() || (m2 = q.front(), m2 != m1))
                    can_queue = false;
                else
                    q.pop();
                if (pq.empty() || (m2 = pq.top(), m2 != m1))
                    can_pq = false;
                else
                    pq.pop();
            }
        }

        if ((int)can_stack + (int)can_queue + (int)can_pq > 1) {
            printf("not sure\n");
        } else if ((int)can_stack + (int)can_queue + (int)can_pq == 1) {
            if (can_stack)
                printf("stack\n");
            else if (can_queue)
                printf("queue\n");
            else if (can_pq)
                printf("priority queue\n");
        } else {
            printf("impossible\n");
        }
    }

    return 0;
}
