#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define int long long

int f(int n, int d) {
    int ret = 0;
    for (int i = d; i <= n; i *= d) {
        ret += n / i;
    }
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    int five = f(n, 5) - f(m, 5) - f(n - m, 5);
    int two = f(n, 2) - f(m, 2) - f(n - m, 2);

    cout << min(five, two);
    
    return 0;
}