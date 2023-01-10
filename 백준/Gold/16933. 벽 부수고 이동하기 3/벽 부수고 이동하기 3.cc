#include <bits/stdc++.h>

using namespace std;

typedef struct _data {
    int y, x, cnt;
    bool day;
    int wait;
} Data;

int N, M, K, MIN = 987654321;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool wall[1000][1000];
int m[1000][1000][11];

void solve() {
    queue<Data> q;
    q.push({0, 0, 0, 1, 0});
    m[0][0][0] = 1;
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;
        bool day = q.front().day;
        int wait = q.front().wait;
        
        if (y == N-1 && x == M-1) {
            MIN = m[y][x][cnt] + wait;;
            break;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (wall[ny][nx] && cnt < K && !m[ny][nx][cnt+1]) {
                if (day) {
                    m[ny][nx][cnt+1] = m[y][x][cnt] + 1;
                    q.push({ny, nx, cnt+1, !day, wait});                    
                }
                else {
                    q.push({y, x, cnt, !day, wait+1});
                }
            }
            else if (!wall[ny][nx] && !m[ny][nx][cnt]) {
                m[ny][nx][cnt] = m[y][x][cnt] + 1;
                q.push({ny, nx, cnt, !day, wait});
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