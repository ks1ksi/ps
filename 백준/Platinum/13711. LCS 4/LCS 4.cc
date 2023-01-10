#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v1(n), v2(n), iv(n+1), tv(n+1), lv(n+1, 1e9);
    for (auto& x : v1) {
        cin >> x;
    }
    for (auto& x : v2) {
        cin >> x;
    }

    for (int i = 0; i < n; i++) {
        iv[v1[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        tv[i] = iv[v2[i]];
    }

    for (auto x : tv) {
        auto tg = lower_bound(lv.begin(), lv.end(), x);
        *tg = x;
    }

    int lis = lower_bound(lv.begin(), lv.end(), 1e9) - lv.begin();
    cout << lis;

    return 0;
}