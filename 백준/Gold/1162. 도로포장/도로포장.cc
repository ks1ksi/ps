#include <bits/stdc++.h>

using namespace std;

typedef struct _Data {
    long long cost;
    int city;
    int pass;
    bool operator< (const _Data& d) const {
        return cost > d.cost;
    }
} Data;

constexpr int MAX = 10001;
int N, M, K;
vector<pair<int, int>> adj[MAX];
long long dist[MAX][21];

void dijkstra() {
    priority_queue<Data> pq;
    pq.push({0, 1, 0});
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < 21; j++) {
            dist[i][j] = LLONG_MAX;
        }
    }
    dist[1][0] = 0;
    while (!pq.empty()) {
        Data d = pq.top();
        pq.pop();
        if (dist[d.city][d.pass] < d.cost) continue;
        for (auto p : adj[d.city]) {
            long long nc = p.first;
            int next = p.second;
            if (dist[next][d.pass] > d.cost+nc) {
                dist[next][d.pass] = d.cost+nc;
                pq.push({d.cost+nc, next, d.pass});
            }
            if (d.pass < K && dist[next][d.pass+1] > d.cost) {
                dist[next][d.pass+1] = d.cost;
                pq.push({d.cost, next, d.pass+1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    
    dijkstra();

    long long m = LLONG_MAX;
    for (int i = 0; i < K+1; i++) {
        m = min(m, dist[N][i]);
    }
    cout << m;

    return 0;
}