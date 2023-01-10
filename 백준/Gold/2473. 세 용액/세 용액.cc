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

    ll ans = 3e9+1;
    int pi, pl, pr;

    for (int i = 0; i < n; i++) {
        int l = 0, r = n-1;
        while (l < r) {
            if (l == i) {
                l++;
                continue;
            }
            if (r == i) {
                r--;
                continue;
            }

            ll cur = v[l] + v[r] + v[i];
            if (ans > abs(cur)) {
                pl = l;
                pr = r;
                pi = i;
                ans = abs(cur);
            }

            if (cur > 0) r--;
            else if (cur < 0) l++;
            else break;

        }
    }

    vector<ll> pv = {v[pl], v[pr], v[pi]};
    sort(pv.begin(), pv.end());

    for (auto x : pv) {
        cout << x << ' ';
    }

    return 0;
}