#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

constexpr int dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
ll N, M, K, X, arr[500][500];

int bfs(int y, int x, ll diff, bool changed[500][500]) {
    int ret = 1;

    queue<pair<int, int>> q;
    q.emplace(y, x);
    changed[y][x] = true;
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;
            if (changed[ny][nx]) continue;
            if (arr[ny][nx] < X - diff) {
                changed[ny][nx] = true;
                q.emplace(ny, nx);
                ret++;
            }
        }

    }

    return ret;
}

int get_cnt(ll diff) {
    int ret = 0;
    bool changed[500][500] = {0};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] >= X - diff) continue;
            if (changed[i][j]) continue;
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k], nx = j + dx[k];
                if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;
                if (abs(arr[i][j] - arr[ny][nx]) > diff) {
                    ret += bfs(i, j, diff, changed);
                    break;
                }
            }
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K >> X;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    ll lo = 0, hi = X;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        int cnt = get_cnt(mid);
        // cout << mid << ' ' << cnt << '\n';
        if (cnt > K) lo = mid + 1;
        else hi = mid - 1;
    }

    cout << lo << '\n';

    return 0;
}