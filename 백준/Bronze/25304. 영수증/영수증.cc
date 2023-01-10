#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, n, t = 0;
    cin >> x >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        t += a * b;
    }
    if (x == t) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}