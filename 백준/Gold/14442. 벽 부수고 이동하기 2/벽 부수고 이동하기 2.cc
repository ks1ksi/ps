#include <bits/stdc++.h>

using namespace std;

int N, M, K, MIN = 987654321;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool wall[1000][1000];
int m[1000][1000][11];

void solve() {
    queue<pair<pair<int, int>, int>> q; //y, x, cnt
    q.push({{0, 0}, 0});
    m[0][0][0] = 1;
    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
        if (y == N-1 && x == M-1) {
            MIN = m[y][x][cnt];
            break;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (wall[ny][nx] && cnt < K && !m[ny][nx][cnt+1]) {
                m[ny][nx][cnt+1] = m[y][x][cnt] + 1;
                q.push({{ny, nx}, cnt+1});
            }
            else if (!wall[ny][nx] && !m[ny][nx][cnt]) {
                m[ny][nx][cnt] = m[y][x][cnt] + 1;
                q.push({{ny, nx}, cnt});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char x;
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++){
            cin >> x;
            if (x == '1') wall[i][j] = true;
        }
    }
    solve();
    if (MIN == 987654321) cout << -1;
    else cout << MIN;
    return 0;
}