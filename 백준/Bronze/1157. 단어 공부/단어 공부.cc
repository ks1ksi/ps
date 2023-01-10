#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> v(26, 0);

    for (auto c : s) {
        v[tolower(c)-'a']++;
    }

    int m = *max_element(v.begin(), v.end());
    if (count(v.begin(), v.end(), m) != 1) {
        cout << "?";
    }
    else {
        cout << (char) (max_element(v.begin(), v.end()) - v.begin() + 'A');
    }

    return 0;
}