#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAX = 1000, INF = 1e9, dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
int N, graph[MAX][MAX], dist[MAX][MAX], res[6][6];
pair<int, int> start;
vector<pair<int, int>> v;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

void dijkstra(pair<int, int> start) {
    fill(&dist[0][0], &dist[MAX-1][MAX], INF);
    pq.emplace(0, start.first, start.second);
    dist[start.first][start.second] = 0;

    while (!pq.empty()) {
        auto [cost, y, x] = pq.top();
        pq.pop();
        if (cost > dist[y][x]) continue;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
            int nc = graph[ny][nx];
            if (dist[ny][nx] > nc + cost) {
                dist[ny][nx] = nc + cost;
                pq.emplace(dist[ny][nx], ny, nx);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == -1) {
                start = {i, j};
                graph[i][j] = 0; // 나중에 비용 계산할 때 -1 처리
            }
            if (graph[i][j] == 0) v.emplace_back(i, j);
        }
    }

    if (v.size() == 1) { // 탈영병이 없는 경우
        cout << 0;
        return 0;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        dijkstra(v[i]);
        for (int j = 0; j < v.size(); j++) {
            auto [a, b] = v[j];
            res[i][j] = dist[a][b];
        }
    }

    vector<int> perm(v.size()-1);
    iota(perm.begin(), perm.end(), 1);
    int ans = 1e9;
    do {
        int tc = 0;
        tc += res[0][perm[0]];
        for (int i = 0; i < perm.size()-1; i++) {
            tc += res[perm[i]][perm[i+1]];
        }
        tc += res[perm[perm.size()-1]][0];
        ans = min(ans, tc);
    } while (next_permutation(perm.begin(), perm.end()));

    cout << ans;

    return 0;
}