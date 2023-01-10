#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }

    int ans = 0, l = 0, r = 0, cur = v[0];

    while (l < n && r < n) {
        if (cur == m) {
            ans++;
            cur -= v[l];
            l++;
        }
        else if (cur < m) {
            r++;
            cur += v[r];
        }
        else {
            cur -= v[l];
            l++;
        }
    }

    cout << ans;

    return 0;
}