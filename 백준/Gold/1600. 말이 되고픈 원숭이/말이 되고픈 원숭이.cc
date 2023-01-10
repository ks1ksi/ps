#include <bits/stdc++.h>

using namespace std;

typedef struct _data {
    int y, x, jumped;
} Data;

int K, W, H, ANS = 987654321;
bool arr[200][200];
int m[200][200][31];
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
const int jy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int jx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void solve() {
    queue<Data> q;
    q.push({0, 0, 0});
    m[0][0][0] = 1;
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int jumped = q.front().jumped;
        q.pop();
        if (y == H-1 && x == W-1) {
            ANS = min(ANS, m[y][x][jumped]);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if (arr[ny][nx]) continue;
            if (m[ny][nx][jumped]) continue;
            m[ny][nx][jumped] = m[y][x][jumped] + 1;
            q.push({ny, nx, jumped});
        }
        if (jumped < K) {
            for (int i = 0; i < 8; i++) {
                int ny = y + jy[i];
                int nx = x + jx[i];
                if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
                if (arr[ny][nx]) continue;
                if (m[ny][nx][jumped+1]) continue;
                m[ny][nx][jumped+1] = m[y][x][jumped] + 1;   
                q.push({ny, nx, jumped+1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> K;
    cin >> W >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> arr[i][j];
        }
    }
    solve();
    if (ANS == 987654321) cout << -1;
    else cout << ANS-1;
    return 0;
}
