#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

// 1 ~ 8
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

int ddy[4] = {-1, -1, 1, 1};
int ddx[4] = {-1, 1, -1, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(n));

    for (auto& v : arr) {
        for (auto& x : v) {
            cin >> x;
        }
    }

    // 방향 - 거리
    vector<pair<int, int>> move;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        move.emplace_back(a, b);
    }

    // y, x
    vector<pair<int, int>> clouds = {
        {n - 1, 0}, {n - 1, 1}, {n - 2, 0}, {n - 2, 1}};

    for (auto [d, s] : move) {
        for (auto& [y, x] : clouds) {
            y = (y + dy[d] * s);
            if (y < 0) y = n + (y % n);
            if (y >= n) y = y % n;

            x = (x + dx[d] * s);
            if (x < 0) x = n + (x % n);
            if (x >= n) x = x % n;
        }

        for (auto [y, x] : clouds) {
            arr[y][x]++;
        }

        for (auto [y, x] : clouds) {
            for (int i = 0; i < 4; i++) {
                int ny = y + ddy[i];
                int nx = x + ddx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                if (arr[ny][nx]) arr[y][x]++;
            }
        }

        vector<pair<int, int>> nclouds;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] >= 2 && find(clouds.begin(), clouds.end(),
                                           make_pair(i, j)) == clouds.end()) {
                    arr[i][j] -= 2;
                    nclouds.emplace_back(i, j);
                }
            }
        }

        clouds = nclouds;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += arr[i][j];
        }
    }

    cout << sum << '\n';

    return 0;
}
