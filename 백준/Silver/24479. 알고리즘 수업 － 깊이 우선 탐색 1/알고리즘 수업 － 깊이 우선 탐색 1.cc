#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int cnt = 1;
vector<set<int>> adj;
int visited[100001];

void dfs(int cur) {
    visited[cur] = cnt++;
    for (auto next : adj[cur]) {
        if (visited[next]) continue;
        dfs(next);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, start;
    cin >> n >> m >> start;
    adj.resize(n+1);
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].emplace(b);
        adj[b].emplace(a);
    }

    dfs(start);
    for (int i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}