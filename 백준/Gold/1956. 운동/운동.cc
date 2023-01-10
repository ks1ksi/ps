#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e9, MAX = 400;
int N, M;
int graph[MAX][MAX];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(&graph[0][0], &graph[MAX-1][MAX], INF);
    cin >> N >> M;
    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a-1][b-1] = c;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < N; i++) {
        ans = min(ans, graph[i][i]);
    }
    cout << (ans == INF ? -1 : ans);
    return 0;
}