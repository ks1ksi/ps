#include <bits/stdc++.h>

using namespace std;

int arr[30][30][30];
int dz[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dx[6] = {1, -1, 0, 0, 0, 0};

void solve(vector<int> start, int l, int r, int c) {
    int ans = 0;
    queue<vector<int>> q;
    q.push(start);
    while (!q.empty()) {
        vector<int> cur = q.front();
        q.pop();
        int z = cur[0];
        int y = cur[1];
        int x = cur[2];
        for (int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];
            //cout << nz << ny << nx << '\n';
            if (nz < 0 || ny < 0 || nx < 0) continue;
            else if (nz >= l || ny >= r || nx >= c) continue;
            else if (arr[nz][ny][nx] == INT_MAX) {
                ans = arr[z][y][x];
                break;
            }
            else if (arr[nz][ny][nx] == 0) {
                arr[nz][ny][nx] = arr[z][y][x] + 1;
                q.push({nz, ny, nx});
            }
        }
    }
    if (ans) cout << "Escaped in " << ans << " minute(s).\n";
    else cout << "Trapped!\n";
    
    // for (int i = 0; i < l; i++) {
    //     for (int j = 0; j < r; j++) {
    //         for (int k = 0; k < c; k++) {
    //             cout << arr[i][j][k] << ' ';
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l, r, c;
    char ch;
    while (1) {
        // input
        cin >> l >> r >> c;
        if (l == 0 || r == 0 || c == 0) break;
        memset(arr, 0, sizeof(arr));
        vector<int> start;
        for (int z = 0; z < l; z++) {
            for (int y = 0; y < r; y++) {
                for (int x = 0; x < c; x++) {
                    cin >> ch;
                    if (ch == 'S') {
                        arr[z][y][x] = 1;
                        start.push_back(z);
                        start.push_back(y);
                        start.push_back(x);
                    }
                    else if (ch == '.') {
                        arr[z][y][x] = 0;
                    }
                    else if (ch == '#') {
                        arr[z][y][x] = -1;
                    }
                    else if (ch == 'E') {
                        arr[z][y][x] = INT_MAX;
                    }
                }
            }
        }
        solve(start, l, r, c);
    }
    return 0;
}

