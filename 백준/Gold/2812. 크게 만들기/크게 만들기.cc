#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<char> v;

    for (int i = 0; i < n; i++) {
        while (k && v.size() && *(v.rbegin()) < s[i]) {
            // cout << "POP: " << *(v.rbegin()) << '\n';
            v.pop_back();
            k--;
        }
        v.push_back(s[i]);
    }

    while (k) {
        v.pop_back();
        k--;
    }

    for (auto c : v) {
        cout << c;
    }

    return 0;
}