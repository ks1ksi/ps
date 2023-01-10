#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(7);
    
    int n, sum = 0;
    cin >> n;
    vector<int> v(n);

    for (auto& x : v) {
        cin >> x;
        sum += x;
    }

    sort(v.begin(), v.end());

    cout << max((ld)sum / n, (ld)v[n-2]) << '\n';

    return 0;
}