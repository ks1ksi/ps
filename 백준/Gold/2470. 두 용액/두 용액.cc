#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto& x : v) {
        cin >> x;
    }

    sort(v.begin(), v.end());

    int l = 0, r = n - 1;

    ll ans = 2e9+1;
    int pl, pr;

    while (l < r) {
        ll cur = v[l] + v[r];

        // cout << v[l] << ' ' << v[r] << ' ' << cur << '\n';

        if (ans > abs(cur)) {
            pl = l;
            pr = r;
            ans = abs(cur);
        }

        if (cur > 0) {
            r--;
        }
        else if (cur < 0) {
            l++;
        }
        else {
            break;
        }

    }

    cout << v[pl] << ' ' << v[pr] << '\n';

    return 0;
}