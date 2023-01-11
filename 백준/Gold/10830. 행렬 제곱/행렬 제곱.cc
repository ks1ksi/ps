#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

constexpr int MOD = 1000;
ll n, b;

vector<vector<int>> dot(vector<vector<int>>& v1, vector<vector<int>>& v2) {
    vector<vector<int>> ret(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ret[i][j] += v1[i][k] * v2[k][j];
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

vector<vector<int>> solve(vector<vector<int>>& v, ll k) {
    if (k == 1) return v;
    auto vec = solve(v, k/2);
    if (k % 2 == 0) return dot(vec, vec);
    else {
        auto tv = dot(vec, vec);
        return dot(tv, v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> b;
    vector<vector<int>> v(n, vector<int>(n));
    for (auto& vec: v) {
        for (auto& x : vec) {
            cin >> x;
            x %= MOD;
        }
    }

    auto ans = solve(v, b);
    for (auto& vec : ans) {
        for (auto& x : vec) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}