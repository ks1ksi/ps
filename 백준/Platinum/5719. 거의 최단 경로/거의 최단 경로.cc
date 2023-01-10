#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 500, INF = 2e9;
int graph[MAX][MAX], dist[MAX];
bool visited[MAX];

void dijkstra(int n, int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    fill(dist, dist+MAX, INF);
    memset(visited, 0, sizeof(visited));
    dist[s] = 0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        for (int i = 0; i < n; i++) {
            if (!graph[cur][i] || visited[i]) continue;
            if (dist[i] > cost+graph[cur][i]) {
                dist[i] = cost+graph[cur][i];
                pq.push({cost+graph[cur][i], i});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        int n, m;
        cin >> n >> m;
        if (!n && !m) break;
        int s, d;
        cin >> s >> d;
        memset(graph, 0, sizeof(graph));
        for (int i = 0; i < m; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            graph[u][v] = p;
        }

        dijkstra(n, s);
        if (dist[d] == INF) {
            cout << -1 << '\n';
            continue;
        }
        queue<int> q;
        vector<pair<int, int>> v;
        q.push(d);
        memset(visited, 0, sizeof(visited));
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (visited[cur]) continue;
            visited[cur] = true;
            for (int i = 0; i < n; i++) {
                if (!graph[i][cur]) continue;
                if (dist[cur] == dist[i]+graph[i][cur]) {
                    v.push_back({i, cur});
                    q.push(i);
                }
            }
        }
        for (auto p : v) {
            graph[p.first][p.second] = 0;
        }

        dijkstra(n, s);
        if (dist[d] == INF) cout << -1 << '\n';
        else cout << dist[d] << '\n';
    }
    return 0;
}