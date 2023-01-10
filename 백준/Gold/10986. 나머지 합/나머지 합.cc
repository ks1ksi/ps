#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> v(n), psum(n);

    for (auto& x : v) {
        cin >> x;
    }

    psum[0] = v[0] % m;

    for (int i = 1; i < n; i++) {
        psum[i] = psum[i-1] + v[i];
        psum[i] %= m;
    }

    vector<int> mcnt(m);
    for (auto x : psum) {
        mcnt[x]++;
    }
    mcnt[0]++;

    ll ans = 0;
    for (auto x : mcnt) {
        ans += (ll)x*(x-1)/2; // overflow
    }

    cout << ans;

    return 0;
}
