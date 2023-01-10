#include <bits/stdc++.h>

using namespace std;

int N, M, P;
int sn[10];
int sc[10];
int arr[1000][1000];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool check_safe(int y, int x) {
    return (y >= 0 && y < N && x >= 0 && x < M);
}

bool bfs(int player, queue<pair<int, int>> &q) {
    int cnt = sn[player];
    while (cnt--) {
        if (q.empty()) return false;
        int sz = q.size();
        while (sz--) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (!check_safe(ny, nx)) continue;
                else if (arr[ny][nx] != 0) continue;
                else {
                    arr[ny][nx] = player;
                    sc[player]++;
                    q.push({ny, nx});
                }
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<queue<pair<int, int>>> v(10);
    char ch;
    cin >> N >> M >> P;
    for (int p = 1; p <= P; p++) {
        cin >> sn[p];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> ch;
            if (ch == '.') arr[i][j] = 0;
            else if (ch == '#') arr[i][j] = -1;
            else {
                int player = ch - '0';
                arr[i][j] = player;
                sc[player]++;
                v[player].push({i, j});
            }
        }
    }
    
    bool sw = true;
    while (sw) {
        sw = false;
        for (int i = 1; i <= P; i++) {
            if (bfs(i, v[i])) sw = true;
        }
    }
    
    // print
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    for (int i = 1; i <= P; i++) {
        cout << sc[i] << ' ';
    }
    
    return 0;
}
