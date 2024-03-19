#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (auto& x : v) {
        cin >> x;
    }

    sort(v.begin(), v.end());

    while (m--) {
        int q;
        cin >> q;
        if (q == 1 || q == 2) {
            ll k;
            cin >> k;
            ll ans = q == 1 ? v.end() - lower_bound(v.begin(), v.end(), k)
                            : v.end() - upper_bound(v.begin(), v.end(), k);
            cout << ans << '\n';
        }
        if (q == 3) {
            ll i, j;
            cin >> i >> j;
            cout << upper_bound(v.begin(), v.end(), j) -
                        lower_bound(v.begin(), v.end(), i)
                 << '\n';
        }
    }

    return 0;
}
