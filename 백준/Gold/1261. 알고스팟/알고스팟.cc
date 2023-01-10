#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAX = 100, INF = 1e9, dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
int N, M, graph[MAX][MAX], dist[MAX][MAX];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

int dijkstra() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dist[i][j] = INF;
        }
    }

    dist[0][0] = 0;
    pq.emplace(0, 0, 0);

    while (!pq.empty()) {
        auto [cost, y, x] = pq.top();
        pq.pop();
        if (dist[y][x] < cost) continue;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;

            int nc = graph[ny][nx];
            if (dist[ny][nx] > cost + nc) {
                dist[ny][nx] = cost + nc;
                pq.emplace(dist[ny][nx], ny, nx);
            }
        }
    }

    return dist[N-1][M-1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            graph[i][j] = c-'0';
        }
    }

    cout << dijkstra() << '\n';

    return 0;
}