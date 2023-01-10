#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAX = 5000, INF = 1e9;
int V, E, P, dist[MAX];
vector<vector<pair<int, int>>> adj;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int dijkstra(int start, int end) {
    fill(dist, dist+MAX, INF);
    dist[start] = 0;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();
        if (cost > dist[cur]) continue;

        for (auto& [ncost, next] : adj[cur]) {
            if (dist[next] > dist[cur] + ncost) {
                dist[next] = dist[cur] + ncost;
                pq.emplace(dist[next], next);
            }
        }
    }
    return dist[end];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E >> P;

    adj.resize(V);

    while (E--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a-1].emplace_back(c, b-1);
        adj[b-1].emplace_back(c, a-1);
    }

    // 1 -> P -> V 최단거리와 1 -> V 최단거리 비교

    int dist1 = dijkstra(0, P-1) + dijkstra(P-1, V-1);
    int dist2 = dijkstra(0, V-1);

    if (dist1 == dist2) cout << "SAVE HIM";
    else cout << "GOOD BYE";

    return 0;
}