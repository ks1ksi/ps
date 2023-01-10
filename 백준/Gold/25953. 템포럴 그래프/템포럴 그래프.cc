#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, t, m, s, e;
int dist[10000];
vector<vector<pair<int, int>>> adj[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t >> m >> s >> e;
    for (int i = 0; i < t; i++) {
        adj[i].resize(n);
        for (int j = 0; j < m; j++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[i][a].emplace_back(b, c);
            adj[i][b].emplace_back(a, c);
        }
    }

    fill(dist, dist+10000, 1e9);
    dist[s] = 0;
    for (int i = 0; i < t; i++) {
        int tmp[10000];
        copy(dist, dist+10000, tmp);
        for (int j = 0; j < n; j++) {
            if (dist[j] == 1e9) continue;
            for (auto [next, cost] : adj[i][j]) {
                if (dist[next] > dist[j] + cost) {
                    tmp[next] = dist[j] + cost;
                }
            }
        }
        copy(tmp, tmp+10000, dist);
    }

    if (dist[e] == 1e9) cout << -1;
    else cout << dist[e];

    return 0;
}