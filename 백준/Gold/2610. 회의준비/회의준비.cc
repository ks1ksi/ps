#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e9, MAX = 100;
int N, M;
int graph[MAX][MAX];
bool visited[MAX];
vector<vector<int>> components;

void bfs() {
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            vector<int> v;
            queue<int> q;
            visited[i] = true;
            v.push_back(i);
            q.push(i);
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int n = 0; n < N; n++) {
                    if (visited[n] || graph[cur][n] == INF) continue;
                    q.push(n);
                    v.push_back(n);
                    visited[n] = true;
                }
            }
            components.push_back(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        graph[a-1][b-1] = 1;
        graph[b-1][a-1] = 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!graph[i][j]) graph[i][j] = INF;
        }
    }

    bfs();

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         if (i == j) graph[i][j] = 0;
    //         if (graph[i][j] == INF) graph[i][j] = 0;
    //     }
    // }

    cout << components.size() << '\n';
    vector<int> ans;
    for (auto v : components) {
        int n = 0, mm = INF;
        for (int i : v) { // 대표
            int m = 0;
            for (int j : v) { // 나머지
                // cout << graph[i][j] << ' ';
                if (i == j) continue;
                if (graph[j][i] > m) { // 최댓값
                    m = graph[j][i];
                }
            }
            if (m < mm) { // 최댓값이 최소가 되도록
                mm = m;
                n = i;
            }
            // cout << '\n';
        }
        // cout << '\n';
        ans.push_back(n+1);
    }
    sort(ans.begin(), ans.end());
    for (int x : ans) {
        cout << x << '\n';
    }

    return 0;
}