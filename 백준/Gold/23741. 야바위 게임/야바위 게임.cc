#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int N, M, X, Y;
vector<vector<int>> adj;
bool visited[2][1001];

void dfs(int cur, int cnt) {
    visited[cnt % 2][cur] = true;
    for (auto next : adj[cur]) {
        if (visited[(cnt+1) % 2][next]) continue;
        dfs(next, cnt+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X >> Y;

    adj.resize(N+1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    if (adj[X].empty()) {
        cout << -1;
        return 0;
    }

    dfs(X, 0);

    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (visited[Y%2][i]) ans.emplace_back(i);
    }
    for (auto x : ans) {
        cout << x << ' ';
    }

    return 0;
}