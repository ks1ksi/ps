#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    while (1) {
        cin >> a >> b;
        if (!a && !b) return 0;

        if (a < b && b % a == 0) cout << "factor\n";
        else if (a > b && a % b == 0) cout << "multiple\n";
        else cout << "neither\n"; 
    }

    return 0;
}