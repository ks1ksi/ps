#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

constexpr int dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
int n, arr[25][25], visited[25][25];
vector<int> ans;

int dfs(int y, int x) {
    int ret = 1;
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny >= n || ny < 0 || nx >= n || nx < 0) continue;
        if (visited[ny][nx] || !arr[ny][nx]) continue;
        ret += dfs(ny, nx);
    }
    return ret;
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] && !visited[i][j]) {
                ans.emplace_back(dfs(i, j));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char x;
            cin >> x;
            arr[i][j] = x-'0';
        }
    }

    solve();
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (auto x : ans) {
        cout << x << '\n';
    }

    return 0;
}