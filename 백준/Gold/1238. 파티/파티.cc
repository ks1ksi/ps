#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, M, X, dist[1000], dist_x[1000];
vector<vector<pair<int, int>>> adj;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X;
    adj.resize(N);

    while (M--) {
        int a, b ,c;
        cin >> a >> b >> c;
        adj[a-1].push_back({c, b-1});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // X부터 모든 지점까지 최단거리 구해놓기
    // 1 ~ N -> X 최단거리 구하고 앞에 구해놓은거랑 더하기

    fill(dist_x, dist_x+1000, 1e9);
    pq.push({0, X-1});
    dist_x[X-1] = 0;
    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();
        
        for (auto [c, next] : adj[cur]) {
            if (dist_x[next] > dist_x[cur] + c) {
                dist_x[next] = dist_x[cur] + c;
                pq.push({dist_x[next], next});
            }
        }
    }

    int ans = 0;
    for (int start = 0; start < N; start++) {
        fill(dist, dist+1000, 1e9);
        pq.push({0, start});
        dist[start] = 0;
        while (!pq.empty()) {
            auto [cost, cur] = pq.top();
            pq.pop();

            for (auto [c, next] : adj[cur]) {
                if (dist[next] > dist[cur] + c) {
                    dist[next] = dist[cur] + c;
                    pq.push({dist[next], next});
                }
            }
        }
        ans = max(ans, dist[X-1] + dist_x[start]);
    }

    cout << ans << '\n';

    return 0;
}