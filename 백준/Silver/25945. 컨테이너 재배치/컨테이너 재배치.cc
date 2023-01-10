#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t = 0;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
        t += x;
    }
    sort(v.rbegin(), v.rend());

    int q = t / n;
    int r = t % n;
    int ans = 0;
    for (auto x : v) {
        int next = r ? q + 1 : q;
        if (next > x) break;
        ans += (x - next);
        if (r) r--;
    }
    cout << ans;

    return 0;
}