#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.end());

    int ans = 0, last = -1e9;
    for (int i = 0; i < n; i++) {
        int s = max(last, v[i].first);
        int e = v[i].second;
        if (s > e) continue;
        ans += e-s;
        last = e;
    }
    cout << ans;

    return 0;
}