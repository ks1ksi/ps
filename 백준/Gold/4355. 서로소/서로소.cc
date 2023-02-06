#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        ll n;
        cin >> n;
        if (!n) break;
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }
        ll ans = n;
        for (ll i = 2; i*i <= n; i++) {
            if (n%i == 0) {
                ans -= ans/i;
                while (n%i == 0) n/=i;
            }
        }
        if (n != 1) {
            ans -= ans/n;
        }
        cout << ans << '\n';
    }

    return 0;
}