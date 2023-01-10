#include <bits/stdc++.h>

using namespace std;

int N;

int gcd (int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int m = b*d;
    int s = a*d + c*b;

    cout << s/gcd(s, m) << ' ' << m/gcd(s, m);

    return 0;
}