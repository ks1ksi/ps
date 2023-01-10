#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> v(n);

    for (auto& x : v) {
        cin >> x;
    }

    ll lo = 0, hi = 2e9;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll rem = 0;

        for (auto x : v) {
            if (mid < x) rem += x - mid;
        }
        
        if (rem < m) hi = mid-1;
        else lo = mid+1;
    }

    cout << hi << '\n';

    return 0;
}