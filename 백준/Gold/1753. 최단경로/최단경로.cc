#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 20001, INF = 1e9;
int V, E, K;
int dist[MAX];
bool visited[MAX];
vector<pair<int, int>> adj[MAX];

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[K] = 0;
    pq.push({0, K});
    while (!pq.empty()) {
        int w, cur;
        w = pq.top().first;
        cur = pq.top().second;
        pq.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        for (auto next : adj[cur]) {
            dist[next.second] = min(dist[next.second], w+next.first);
            pq.push({dist[next.second], next.second});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    cin >> K;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    for (int i = 1; i < V+1; i++) {
        dist[i] = INF;
    }
    dijkstra();
    for (int i = 1; i < V+1; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
    return 0;
}