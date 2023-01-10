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

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);
        cout << a*b/gcd(a, b) << '\n';
    }

    return 0;
}