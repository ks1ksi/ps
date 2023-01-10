#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 501;
constexpr long long INF = 1e18;
int T, N, M, W;
vector<vector<pair<int, long long>>> adj;
long long dist[MAX];

// check negative cycle by bellman ford
bool check(int start) {
    fill(dist, dist+MAX, INF);
    dist[start] = 0;
    bool ret = false;
    for (int i = 0; i < 2*N; i++) {
        for (int j = 1; j < N+1; j++) {
            // if (dist[j] == INF) continue;
            for (auto p : adj[j]) {
                int next = p.first;
                long long nc = p.second;
                if (dist[next] > dist[j] + nc) {
                    dist[next] = dist[j] + nc;
                    if (i >= N-1) {
                        ret = true;
                    }
                }
            }
        }
    }
    return ret;
    // if (dist[start] == -INF) return true;
    // return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N >> M >> W;
        int a, b, c;
        adj.clear();
        adj = vector<vector<pair<int, long long>>>(N+1);
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        for (int i = 0; i < W; i++) {
            cin >> a >> b >> c;
            adj[a].push_back({b, -c});
        }
        if (check(1)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}