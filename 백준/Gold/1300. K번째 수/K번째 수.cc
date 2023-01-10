#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    ll lo = 0, hi = 1e10;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (i*n < mid) cnt += n;
            else cnt += mid / i;
        }
        if (cnt < k) lo = mid + 1;
        else hi = mid - 1;
    }

    cout << lo << '\n';

    return 0;
}