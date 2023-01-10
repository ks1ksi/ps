#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e9, MAX = 401;
int N, M, S;
int graph[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1][b-1] = 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!graph[i][j]) graph[i][j] = INF;
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }

    cin >> S;
    for (int i = 0; i < S; i++) {
        int a, b;
        cin >> a >> b;
        if (graph[a-1][b-1] == INF && graph[b-1][a-1] == INF) cout << 0 << '\n';
        else if (graph[a-1][b-1] == INF && graph[b-1][a-1] != INF) cout << 1 << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}