#include <bits/stdc++.h>

using namespace std;

typedef struct _DisjSet {
    int parent[1000001] = {0,};
    
    void init() {
        memset(parent, -1, sizeof(parent));
    }
    
    int find(int n) {
        if (parent[n] < 0) return n;
        return parent[n] = find(parent[n]);
    }
    
    void Union(int n1, int n2) {
        n1 = find(n1);
        n2 = find(n2);
        if (n1 == n2) return;
        parent[n1] += parent[n2];
        parent[n2] = n1;
    }
    
} DisjSet;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int F, cnt = 1;
        string s1, s2;
        map<string, int> m;
        DisjSet d;
        d.init();
        cin >> F;
        while (F--) {
            cin >> s1 >> s2;
            if (m.find(s1) == m.end()) {
                m.insert({s1, cnt++});
            }
            if (m.find(s2) == m.end()) {
                m.insert({s2, cnt++});
            }
            d.Union(m.find(s1)->second, m.find(s2)->second);
            cout << -d.parent[d.find(m.find(s1)->second)] << '\n';
        }
    }
    return 0;
}