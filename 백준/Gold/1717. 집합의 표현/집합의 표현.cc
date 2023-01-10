#include <bits/stdc++.h>

using namespace std;

int N, M;

typedef struct _DisjSet {
    int parent[1000001] = {0,};
    
    void init(int n) {
        for (int i = 0; i < n+1; i++) {
            parent[i] = i;
        }
    }
    
    int find(int n) {
        if (parent[n] == n) return n;
        return parent[n] = find(parent[n]);
    }
    
    void Union(int n1, int n2) {
        n1 = find(n1);
        n2 = find(n2);
        if (n1 == n2) return;
        parent[n2] = n1;
    }
    
} DisjSet;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    DisjSet d;
    d.init(N);
    
    for (int i = 0; i < M; i++) {
        int f, a, b;
        cin >> f >> a >> b;
        if (f) {
            if (d.find(a) == d.find(b)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            d.Union(a, b);
        }
    }
    return 0;
}