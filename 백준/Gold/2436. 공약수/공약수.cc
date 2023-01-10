#include <bits/stdc++.h>

using namespace std;

#define int long long

int gcd (int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int g, l;
    cin >> g >> l;

    int a = 1e9, b = 1e9;
    for (int i = g; i*i <= g*l; i++) {
        if ((g*l)%i) continue;
        if (gcd(i, g*l/i) == g && a+b > i+g*l/i) {
            a = i;
            b = g*l/i;
        }
    }
    cout << a << ' ' << b << '\n';
    return 0;
}