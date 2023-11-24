#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

// 왕복 거리 최댓값 구하기
int f(vector<vector<int>>& v, int node, vector<int>& friends) {
    int ret = 0;
    for (auto& x : friends) {
        if (v[node][x] + v[x][node] >= 1e9) return -1;
        ret = max(ret, v[node][x] + v[x][node]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1));
    for (auto& v : dist) {
        fill(v.begin(), v.end(), 1e9);
    }

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    int k;
    cin >> k;
    vector<int> friends(k);
    for (auto& x : friends) {
        cin >> x;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // for (auto& v : dist) {
    //     for (auto& x : v) {
    //         cout << x << ' ';
    //     }
    //     cout << '\n';
    // }

    int md = 1e9;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int res = f(dist, i, friends);

        if (res == -1) continue;
        if (res < md) {
            md = res;
            ans = {i};
        } else if (res == md) {
            ans.emplace_back(i);
        }
    }

    for (auto& x : ans) {
        cout << x << ' ';
    }

    return 0;
}
