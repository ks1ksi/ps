#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    ll cur = 0;

    for (auto [start, t] : v) {
        if (cur < start) cur = start + t;
        else cur += t;
    }

    cout << cur << '\n';

    return 0;
}