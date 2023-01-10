#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second < p2.second;
}

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

    vector<pair<int, int>> lv;
    vector<int> idx, before(n, -1);

    for (int i = 0; i < n; i++) {
        pair<int, int> p = v[i];
        auto [a, b] = p;
        auto tg = lower_bound(lv.begin(), lv.end(), p, cmp);
        if (tg == lv.end()) {
            lv.emplace_back(p);
            idx.emplace_back(i);
            if (idx.size() > 1) before[i] = idx[idx.size()-2];
        }
        else {
            *tg = p;
            idx[tg - lv.begin()] = i;
            if (tg != lv.begin()) before[i] = idx[tg - lv.begin() - 1];
        }
    }

    // for (auto x : idx) {
    //     cout << x << ' ';
    // }
    // cout << '\n';

    // for (auto x : before) {
    //     cout << x << ' ';
    // }
    // cout << '\n';

    cout << n - lv.size() << '\n';
    set<pair<int, int>> lis;
    int cur = idx[idx.size()-1];
    while (cur >= 0) {
        lis.emplace(v[cur]);
        cur = before[cur];
    }

    // for (auto [a, b] : lis) {
    //     cout << a << ' ' << b << '\n';
    // }

    for (auto& p : v) {
        if (lis.find(p) == lis.end()) cout << p.first << '\n';
    }

    return 0;
}
