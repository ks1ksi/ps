#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set<int> a, b;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.emplace(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.emplace(x);
    }

    vector<int> v1, v2;
    set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(v1, v1.begin()));
    set_difference(b.begin(), b.end(), a.begin(), a.end(), inserter(v2, v2.begin()));

    cout << v1.size() + v2.size() << '\n';

    return 0;
}