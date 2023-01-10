#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 1001, INF = 1e9;
int N, M;
vector<pair<int, int>> adj[MAX]; // cost, node
int dist[MAX], prev_node[MAX];
bool visited[MAX];

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist+MAX, INF);
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        for (auto p : adj[cur]) {
            int nc = p.first;
            int next = p.second;
            if (visited[next]) continue;
            if (dist[next] > cost+nc) {
                dist[next] = cost+nc;
                prev_node[next] = cur;
                pq.push({cost+nc, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >>c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    dijkstra();
    cout << N - 1;
    for (int i = 2; i <= N; i++) {
        cout << '\n' << i << ' ' << prev_node[i];
    }
    return 0;
}