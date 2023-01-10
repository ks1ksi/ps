#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int s = 0;
    vector<int> v(5);
    for (auto& x : v) {
        cin >> x;
        s += x;
    }
    sort(v.begin(), v.end());

    cout << s/5 << '\n' << v[2];

    return 0;
}