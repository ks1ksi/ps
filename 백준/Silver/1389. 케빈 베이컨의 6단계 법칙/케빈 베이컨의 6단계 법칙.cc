#include <bits/stdc++.h>

using namespace std;

int N, M;
int graph[100][100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1][b-1] = 1;
        graph[b-1][a-1] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!graph[i][j]) graph[i][j] = 987654321;
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << graph[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int m = 987654321;
    int ans = -1;

    for (int i = 0; i < N; i++) {
        int s = 0;
        for (int j = 0; j < N; j++) {
            s += graph[i][j];
        }
        if (m > s) {
            m = s;
            ans = i+1;
        }
    }
    cout << ans;

    return 0;
}