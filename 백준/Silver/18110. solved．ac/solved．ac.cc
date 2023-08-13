#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> v(n);

    for (auto &x : v) {
        cin >> x;
    }

    sort(v.begin(), v.end());

    int sum = 0;
    int cut = round(0.15 * n);

    for (int i = cut; i < n - cut; i++) {
        sum += v[i];
    }

    cout << round((ld)sum / (n - cut * 2)) << '\n';

    return 0;
}