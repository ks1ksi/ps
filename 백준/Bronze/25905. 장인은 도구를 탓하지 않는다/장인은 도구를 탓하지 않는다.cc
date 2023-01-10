#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(7);

    vector<ld> v(10);
    for (auto& x : v) {
        cin >> x;
    }
    sort(v.begin(), v.end());

    ld ans = 1e9;
    for (int i = 1; i < 10; i++) {
        ans = ans * v[i] / i;
    }

    cout << ans << '\n';

    return 0;
}