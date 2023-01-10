#include <bits/stdc++.h>

using namespace std;

int N, M, MIN = 987654321;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

char maze[50][50];
int m[50][50][1<<6];

void solve(int sy, int sx) {
    queue<pair<pair<int, int>, int>> q; // y, x, key
    q.push({{sy, sx}, 0});
    m[sy][sx][0] = 1;
    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int k = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            char next = maze[ny][nx];
            if (next == '#') continue;
            if (next == '1') {
                MIN = min(MIN, m[y][x][k]+1);
                continue;
            }
            if (!m[ny][nx][k]) {
                if (next >= 'a' && next <= 'f') {
                    m[ny][nx][k|1<<(next-'a')] = m[y][x][k]+1;
                    q.push({{ny, nx}, k|(1<<next-'a')});
                }
                else if (next >= 'A' && next <= 'F') {
                    if (k&(1<<next-'A')) {
                        m[ny][nx][k] = m[y][x][k]+1;
                        q.push({{ny, nx}, k});
                    }
                }
                else {
                    m[ny][nx][k] = m[y][x][k]+1;
                    q.push({{ny, nx}, k});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int sy, sx;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == '0') {
                sy = i;
                sx = j;
            }
        }
    }
    solve(sy, sx);
    if (MIN == 987654321) cout << -1;
    else cout << MIN-1;    
    return 0;
}