#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int dfs(int cur, int prev, vector<vector<int>>& adj, vector<int>& visited) {
    if (visited[cur]) return -1;
    visited[cur] = 1;

    int ret = 0;
    for (auto& next : adj[cur]) {
        if (next == prev) continue;
        ret += dfs(next, cur, adj, visited);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = -1, m = -1, cnt = 0;
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        cnt++;

        vector<vector<int>> adj(n + 1);
        while (m--) {
            int a, b;
            cin >> a >> b;
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }

        vector<int> visited(n + 1);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dfs(i, 0, adj, visited) == 0) ans++;
        }

        cout << "Case " << cnt << ": ";
        if (ans == 0) {
            cout << "No trees.\n";
        } else if (ans == 1) {
            cout << "There is one tree.\n";
        } else {
            cout << "A forest of " << ans << " trees.\n";
        }
    }

    return 0;
}
