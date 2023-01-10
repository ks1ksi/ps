#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAX = 125, INF = 1e9, dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
int N, graph[MAX][MAX], dist[MAX][MAX], PN;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

int dijkstra() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = INF;
        }
    }

    dist[0][0] = graph[0][0];
    pq.emplace(dist[0][0], 0, 0);

    while (!pq.empty()) {
        auto [cost, y, x] = pq.top();
        pq.pop();
        if (dist[y][x] < cost) continue;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;

            int nc = graph[ny][nx];
            if (dist[ny][nx] > cost + nc) {
                dist[ny][nx] = cost + nc;
                pq.emplace(dist[ny][nx], ny, nx);
            }
        }
    }

    return dist[N-1][N-1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> N;
        if (N == 0) break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> graph[i][j];
            }
        }

        cout << "Problem " << ++PN << ": " << dijkstra() << '\n';

    }

    return 0;
}