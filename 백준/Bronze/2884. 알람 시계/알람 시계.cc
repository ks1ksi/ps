#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, m, x;
    cin >> h >> m;
    x = h * 60 + m - 45;

    if (x < 0) x += 1440;

    cout << x / 60 << ' ' << x % 60 << '\n';

    return 0;
}