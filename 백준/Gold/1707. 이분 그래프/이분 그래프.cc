#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int v, e;
        cin >> v >> e;

        vector<vector<int>> adj(v+1);
        int visited[20001] = {0};

        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }

        auto f = [&](int start) {
            queue<int> q;
            q.emplace(start);
            visited[start] = 1;
            while (q.size()) {
                int cur = q.front();
                q.pop();
                for (auto next : adj[cur]) {
                    if (visited[next] == visited[cur]) return false;
                    if (visited[next] == visited[cur]%2+1) continue;
                    visited[next] = visited[cur]%2+1;
                    q.emplace(next);
                }
            }
            return true;
        };

        bool flag = true;
        for (int i = 1; i <= v; i++) {
            if (visited[i]) continue;
            if (!f(i)) {
                cout << "NO\n";
                flag = false;
                break;
            }
        }
        if (flag) cout << "YES\n";
    }

    return 0;
}