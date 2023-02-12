#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N, C;

void solve(vector<ll>& v, map<ll ,ll>& m, ll idx, ll cur) {
    if (idx == v.size()) {
        m[cur]++;
        return;
    }
    if (cur + v[idx] <= C) solve(v, m, idx + 1, cur + v[idx]);
    solve(v, m, idx + 1, cur);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;
    vector<ll> v(N);
    for (auto& x : v) {
        cin >> x;
    }

    map<ll, ll> m1, m2; // sum, count
    vector<ll> v1(v.begin(), v.begin()+v.size()/2);
    vector<ll> v2(v.begin()+v.size()/2, v.end());
    solve(v1, m1, 0, 0);
    solve(v2, m2, 0, 0);

    // for (auto [a, b] : m1) {
    //     cout << a << ' ' << b << '\n';
    // }
    // for (auto [a, b] : m2) {
    //     cout << a << ' ' << b << '\n';
    // }

    vector<pair<ll, ll>> pv1, pv2;
    for (auto p : m1) {
        pv1.emplace_back(p);
    }
    for (auto p : m2) {
        pv2.emplace_back(p);
    }

    ll ans = 0;
    for (auto [a, b] : pv1) {
        for (auto [c, d] : pv2) {
            if (a + c <= C) ans += b * d;
        }
    }

    cout << ans;

    return 0;
}