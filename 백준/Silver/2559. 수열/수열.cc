#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    for (auto& x : v) {
        cin >> x;
    }

    int cur = 0;
    for (int i = 0; i < k; i++) {
        cur += v[i];
    }

    int ans = cur;
    for (int i = k; i < n; i++) {
        cur -= v[i-k];
        cur += v[i];
        ans = max(ans, cur);
    }

    cout << ans;

    return 0;
}
