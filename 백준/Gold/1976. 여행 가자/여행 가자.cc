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
    
    int x;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> x;
            if (x) d.Union(i, j);
        }
    }
    
    int start;
    cin >> start;
    bool sw = true;
    for (int i = 1; i < M; i++) {
        cin >> x;
        if (!(d.find(start-1) == d.find(x-1))) {
            sw = false;
            break;
        }
    }
    if (sw) cout << "YES";
    else cout << "NO";
    
    return 0;
}