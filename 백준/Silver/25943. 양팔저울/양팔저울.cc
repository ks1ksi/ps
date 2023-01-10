#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, l, r;
    cin >> n >> l >> r;

    for (int i = 0; i < n-2; i++) {
        int x;
        cin >> x;
        if (l > r) r += x;
        else l += x;
    }

    int diff = abs(l - r);
    int ans = 0;
    vector<int> v = {100, 50, 20, 10, 5, 2, 1};
    for (auto x : v) {
        if (diff >= x) {
            ans += diff / x;
            diff %= x;
        }
    }
    cout << ans;

    return 0;
}