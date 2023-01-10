#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MAX = 500, INF = 1e18;
ll N, M, dist[MAX];
vector<vector<pair<ll, int>>> adj;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    adj.resize(N);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a-1].emplace_back(c, b-1); // cost, next
    }

    int start = 0;
    fill(dist, dist+MAX, INF);
    dist[start] = 0;
    bool neg = false;

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (dist[i] == INF) continue;
            for (auto p : adj[i]) {
                auto [cost, next] = p;
                if (dist[next] > dist[i] + cost) {
                    dist[next] = dist[i] + cost;
                    if (k == N-1) neg = true;
                }
            }
        }
    }

    if (neg) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 1; i < N; i++) {
        if (dist[i] == INF) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}