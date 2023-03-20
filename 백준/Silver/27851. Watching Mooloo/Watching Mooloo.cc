#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    
    for (auto& x : v) {
        cin >> x;
    }

    ll ans = 0;
    int s = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] - v[i-1] > k) {
            ans += (v[i-1] - v[s] + 1 + k);
            s = i;
        }
    }

    ans += (v[n-1] - v[s] + 1 + k);

    cout << ans << '\n';

    return 0;
}