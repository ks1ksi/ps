#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    vector<int> qv(q);

    for (auto& x : v) cin >> x;
    for (auto& x : qv) cin >> x;

    vector<int> cnt(n);
    cnt[0] = v[0];
    for (int i = 1; i < n; i++) {
        cnt[i] = cnt[i - 1] + v[i] - v[i - 1] - 1;
    }

    for (auto& x : qv) {
        cout << lower_bound(cnt.begin(), cnt.end(), x) - cnt.begin() + x - 1
             << ' ';
    }

    return 0;
}
