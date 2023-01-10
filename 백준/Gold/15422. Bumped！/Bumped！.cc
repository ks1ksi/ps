#include <bits/stdc++.h>

using namespace std;

#define int long long

constexpr int MAX = 50000;
constexpr long long INF = LLONG_MAX;
int N, M, F, S, T; // city, road, flight, start, dest
vector<pair<int, int>> adj[2*MAX];
bool visited[2*MAX];
int dist[2*MAX];

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
    }
    for (int i = MAX; i < MAX+N; i++) {
        dist[i] = INF;
    }
    dist[S] = 0;
    pq.push({0, S});
    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        for (auto p : adj[cur]) {
            int next = p.first;
            int nc = p.second;
            if (dist[next] > dist[cur]+nc) {
                dist[next] = dist[cur]+nc;
                pq.push({cost+nc, next});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> F >> S >> T;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        adj[a+MAX].push_back({b+MAX, c});
        adj[b+MAX].push_back({a+MAX, c});
    }
    for (int i = 0; i < F; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v+MAX, 0});
    }
    dijkstra();
    cout << min(dist[T], dist[T+MAX]);
    return 0;
}