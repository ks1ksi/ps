#include <bits/stdc++.h>

using namespace std;

int N, M, K, cost[10000];

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
        if (cost[n1] < cost[n2]) parent[n2] = n1;
        else parent[n1] = n2;
    }
    
} DisjSet;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;

    DisjSet d;
    d.init(N);
    
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }
     
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        d.Union(a-1, b-1);
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (d.find(N) == d.find(i)) continue;
        ans += cost[d.find(i)];
        d.Union(N, i);            
    }
    if (ans <= K) cout << ans;
    else cout << "Oh no";
    return 0;
}