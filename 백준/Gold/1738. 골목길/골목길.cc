#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 101;
constexpr long long INF = 1e18;
int N, M;
vector<pair<int, long long>> adj[MAX];
long long dist[MAX];
int pnode[MAX];

void solve() {
    fill(dist, dist+MAX, INF);
    dist[1] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N+1; j++) {
            for (auto p : adj[j]) {
                if (dist[j] != INF && dist[p.first] > dist[j] + p.second) {
                    dist[p.first] = dist[j] + p.second;
                    pnode[p.first] = j;
                    if (i == N-1) {
                        dist[p.first] = -INF;
                    }
                }
            }
        }
    }

    if (dist[N] == INF || dist[N] == -INF) cout << -1;
    else {
        int x = N;
        vector<int> v;
        while (x != 0) {
            v.push_back(x);
            x = pnode[x];
        }
        for (auto i = v.rbegin(); i != v.rend(); i++) {
            cout << *i << ' ';
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, -c});
    }
    solve();
    return 0;
}