#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;

class UF {
    private:
        vi parent, rank;
        int set_num;

        int find_grand_parent(int m) {
            return (parent[m] == m ? m :
                    parent[m] = find_grand_parent(parent[m]));
        }

    public:
        UF(int size) {
            set_num = size;
            rank.assign(size, 0);
            parent.assign(size, 0);
            for (int i = 0; i < size; i++)
                parent[i] = i;
        }

        void union_sets(int a, int b) {
            int parent_a = find_grand_parent(a), 
                parent_b = find_grand_parent(b);

            if (parent_a != parent_b) {
                if (rank[parent_a] > rank[parent_b])
                    parent[parent_b] = parent_a;
                else {
                    if (rank[parent_a] == rank[parent_b])
                        ++rank[parent_b];
                    parent[parent_a] = parent_b;
                }
            }
        }

        bool is_same_set(int a, int b) {
            int parent_a = find_grand_parent(a), 
                parent_b = find_grand_parent(b);

            return parent_a == parent_b;
        }
};

int main() {
    int cases;
    scanf("%d\n\n", &cases);
    
    while (cases--) {
        int n;
        char line[110];

        scanf("%d\n", &n);

        UF union_find(n);
        int result[2] = {0,}, ci, cj;
        char type;
        while (fgets(line, 100, stdin) != NULL && strcmp(line, "\n")) {
            sscanf(line, "%c %d %d", &type, &ci, &cj);
            if (type == 'c')
                union_find.union_sets(ci - 1, cj - 1);
            else
                ++result[(ssize_t)union_find.is_same_set(ci - 1, cj - 1)];
        }

        printf("%d,%d\n", result[1], result[0]);
        if (cases)
            printf("\n");
    }

    return 0;
}
