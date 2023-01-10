#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pics(n);
    vector<int> frs(m);

    for (auto& [a, b] : pics) { // value, size
        cin >> b >> a;
    }

    for (auto& x : frs) {
        cin >> x;
    }

    sort(pics.begin(), pics.end());
    sort(frs.begin(), frs.end());
    int ans = 0;

    for (int i = n-1; i >= 0 && ans < m; i--) {
        auto [value, sz] = pics[i];
        if (sz > frs[m-ans-1]) continue;
        ans++;
    }

    cout << ans << '\n';

    return 0;
}
