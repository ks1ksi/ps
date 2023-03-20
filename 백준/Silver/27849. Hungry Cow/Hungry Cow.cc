#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, T;
    cin >> N >> T;

    vector<pair<ll, ll>> v;
    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }

    ll ans = 0, rem = 0;
    for (int i = 0; i < N-1; i++) {
        auto [d1, x1] = v[i];
        auto [d2, x2] = v[i+1];

        if (x1 + rem > d2 - d1) {
            ans += d2 - d1;
            rem = rem + x1 - (d2 - d1);
        }
        else {
            ans += x1 + rem;
            rem = 0;
        }
    }

    if (v[N-1].second + rem > T+1 - v[N-1].first) {
        ans += T+1 - v[N-1].first;
    }
    else {
        ans += v[N-1].second + rem;
    }

    cout << ans << '\n';

    return 0;
}