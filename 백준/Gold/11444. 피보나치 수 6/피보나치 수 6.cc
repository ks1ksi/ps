#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

constexpr ll MOD = 1e9+7;
ll n;

vector<vector<ll>> dot(vector<vector<ll>>& v1, vector<vector<ll>>& v2) {
    vector<vector<ll>> ret(2, vector<ll>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                ret[i][j] += v1[i][k] * v2[k][j];
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

vector<vector<ll>> solve(vector<vector<ll>>& v, ll k) {
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

    cin >> n;

    if (n == 1 || n == 2) {
        cout << 1;
        return 0;
    }

    vector<vector<ll>> v = {{1, 1}, {1, 0}};
    auto rv = solve(v, n-1);
    cout << rv[0][0] << '\n';

    return 0;
}