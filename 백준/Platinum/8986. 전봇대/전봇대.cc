#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<ll> v;

ll sz(int k) {
    ll ret = 0;
    for (int i = 1; i < N; i++) {
        ret += abs(v[i] - 1LL*k*i);
    }
    return ret;
}

int main() {

    cin >> N;
    v.resize(N);
    for (auto& x : v) {
        cin >> x;
    }

    int lo = 0, hi = 1e9;
    while (hi - lo >= 3) {
        int p = lo + (hi - lo)/3;
        int q = lo + (hi - lo)/3*2;
        
        if (sz(p) > sz(q)) lo = p + 1;
        else hi = q - 1;
    }

    ll ans = LLONG_MAX;
    for (int x = lo; x <= hi; x++) {
        ans = min(ans, sz(x));
    }
    cout << ans << '\n';

    return 0;
}