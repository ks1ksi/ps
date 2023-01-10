#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll a, b ,c;
    cin >> a >> b >> c;

    ll t = ceil((c - a)*1.0 / (a - b));

    cout << t + 1;

    return 0;
}