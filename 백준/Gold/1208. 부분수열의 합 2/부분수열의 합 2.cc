#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void f(vector<ll>& v, unordered_map<ll, ll>& m, ll cur, int idx) {
    if (idx == v.size()) {
        m[cur]++;
        return;
    }
    f(v, m, cur, idx+1);
    f(v, m, cur + v[idx], idx+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;
    vector<ll> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    vector<ll> v1(v.begin(), v.begin() + v.size() / 2), v2(v.begin() + v.size() / 2, v.end());
    unordered_map<ll, ll> m1, m2; // sum, count
    f(v1, m1, 0, 0);
    f(v2, m2, 0, 0);

    ll ans = 0;
    for (auto [a, b] : m1) {
        ans += m2[s - a] * b;
    }
    if (s == 0) ans--;
    cout << ans;

    return 0;
}