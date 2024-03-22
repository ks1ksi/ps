#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int calc(int l, int r, vector<int>& v) { return (r - l - 1) * min(v[l], v[r]); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }

    int l = 0, r = n - 1;
    int ans = 0;

    while (l < r) {
        ans = max(ans, calc(l, r, v));
        if (v[l] >= v[r])
            r--;
        else
            l++;
    }

    cout << ans << '\n';

    return 0;
}
