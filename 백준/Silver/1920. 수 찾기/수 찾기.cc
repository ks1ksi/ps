#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    set<int> s;
    vector<int> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        v.emplace_back(x);
    }

    for (auto x : v) {
        cout << (s.count(x) ? 1 : 0) << '\n';
    }

    return 0;
}