#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto& [a, b] : v) {
        cin >> a >> b;
    }
    sort(v.begin(), v.end());

    vector<int> lv(n, 1e9);

    for (auto& [_, x] : v) {
        auto tg = lower_bound(lv.begin(), lv.end(), x);
        *tg = x;
    }

    int lis = lower_bound(lv.begin(), lv.end(), 1e9) - lv.begin();
    cout << n - lis;

    return 0;
}
