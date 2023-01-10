#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int ans = 0;
    for (auto c : s) {
        if (c <= 'C') ans += 3;
        else if (c <= 'F') ans += 4;
        else if (c <= 'I') ans += 5;
        else if (c <= 'L') ans += 6;
        else if (c <= 'O') ans += 7;
        else if (c <= 'S') ans += 8;
        else if (c <= 'V') ans += 9;
        else if (c <= 'Z') ans += 10;
        else ans += 11;
    }
    
    cout << ans;

    return 0;
}