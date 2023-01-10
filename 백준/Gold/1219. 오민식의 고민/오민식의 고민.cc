#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 50;
constexpr long long INF = 1e18;
int N, M, S, E;
vector<pair<int, long long>> adj[MAX];
vector<int> gold;
long long dist[MAX];

void solve() {
    fill(dist, dist+MAX, -INF);
    dist[S] = gold[S];
    for (int i = 0; i < 2*N; i++) {
        for (int j = 0; j < N; j++) {
            for (auto p : adj[j]) {
                long long nc = dist[j] - p.second + gold[p.first];
                if (dist[j] != -INF && dist[p.first] < nc) {
                    dist[p.first] = nc;
                    if (i >= N-1) {
                        dist[p.first] = INF;
                    }
                }
            }
        }
    }
    if (dist[E] == -INF) cout << "gg";
    else if (dist[E] == INF) cout << "Gee";
    else cout << dist[E];
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S >> E >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    gold = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> gold[i];
    }
    solve();
    // cout << '\n';
    // for (int i = 0; i < N; i++) {
    //     cout << dist[i] << ' ';
    // }
    return 0;
}