#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    sort(s.rbegin(), s.rend());
    cout << s;

    return 0;
}