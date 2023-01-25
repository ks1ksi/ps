#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

constexpr int dy[8] = {2, 2, 1, 1, -1, -1, -2, -2};
constexpr int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n));

        int sy, sx, ey, ex;
        cin >> sy >> sx >> ey >> ex;

        auto solve = [&]() -> int {
            queue<pair<int, int>> q;
            q.emplace(sy, sx);
            arr[sy][sx] = 1;
            while (q.size()) {
                auto [y, x] = q.front();
                q.pop();
                for (int i = 0; i < 8; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if (ny >= n || ny < 0 || nx >= n || nx < 0) continue;
                    if (arr[ny][nx]) continue;
                    q.emplace(ny, nx);
                    arr[ny][nx] = arr[y][x] + 1;
                }
            }
            return arr[ey][ex];
        };

        cout << solve() - 1 << '\n';

    }

    return 0;
}