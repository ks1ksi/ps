#include <bits/stdc++.h>

using namespace std;
int R, C, MAX = 0;
char arr[20][20];
bool visited[26];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void solve(int y, int x, int cnt) {
    MAX = max(MAX, cnt);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= R || nx >= C || ny < 0 || nx < 0) continue;
        if (visited[arr[ny][nx] - 'A']) continue;
        visited[arr[ny][nx] - 'A'] = true;
        solve(ny, nx, cnt+1);
        visited[arr[ny][nx] - 'A'] = false;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }
    visited[arr[0][0] - 'A'] = true;
    solve(0, 0, 1);
    cout << MAX;
    return 0;
}