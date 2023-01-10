#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    sort(v.rbegin(), v.rend());

    cout << v[k-1];

    return 0;
}