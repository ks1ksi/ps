#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> x;

    if (x % 400 == 0) cout << 1;
    else if (x % 100 == 0) cout << 0;
    else if (x % 4 == 0)  cout << 1;
    else cout << 0;

    return 0;
}