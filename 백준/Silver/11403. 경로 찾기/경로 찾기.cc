#include <bits/stdc++.h>

using namespace std;

int N;
int graph[100][100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            if (x) graph[i][j] = x;
            else graph[i][j] = 987654321;
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (graph[i][j] == 987654321 ? 0 : 1) << ' ';
        }
        cout << '\n';
    }

    return 0;
}