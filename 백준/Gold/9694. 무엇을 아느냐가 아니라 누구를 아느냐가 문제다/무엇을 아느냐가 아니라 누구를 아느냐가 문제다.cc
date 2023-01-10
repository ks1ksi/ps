#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, cnt = 1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> adj(m);
        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].emplace_back(b, c);
            adj[b].emplace_back(a, c);
        }

        int dist[20], before[20] = {0};
        fill(dist, dist+20, 1e9);
        dist[0] = 0;
        before[0] = -1;

        for (int k = 0; k < m; k++) {
            for (int i = 0; i < m; i++) {
                if (dist[i] == 1e9) continue;
                for (auto& [next, c] : adj[i]) {
                    if (dist[next] > dist[i] + c) {
                        dist[next] = dist[i] + c;
                        before[next] = i;
                    }
                }
            }
        }

        cout << "Case #" << cnt++ << ": ";
        if (dist[m-1] == 1e9) cout << -1;
        else {
            vector<int> ans;
            int node = m-1;
            while (node != -1) {
                ans.emplace_back(node);
                node = before[node];
            }
            for(auto x = ans.rbegin(); x != ans.rend(); x++) {
                cout << *x << ' ';
            }
        }
        cout << '\n';

    }

    return 0;
}