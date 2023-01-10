#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> x;
    if (x >= 90) cout << "A\n";
    else if (x >= 80) cout << "B\n";
    else if (x >= 70) cout << "C\n";
    else if (x >= 60) cout << "D\n";
    else cout << "F\n";

    return 0;
}