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
    sort(v.begin(), v.end());

    ll lo = 0, hi = 1e9;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;

        int last = v[0], cnt = 1;
        for (int i = 1; i < n; i++) {
            if (v[i] - last < mid) continue;
            last = v[i];
            cnt++;
        }

        if (cnt >= m) lo = mid + 1;
        else hi = mid - 1;

    }

    cout << hi << '\n';

    return 0;
}

