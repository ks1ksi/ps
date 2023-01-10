#include <bits/stdc++.h>

using namespace std;

int gcd (int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> x >> y;
    cout << x+y-gcd(x, y);

    return 0;
}