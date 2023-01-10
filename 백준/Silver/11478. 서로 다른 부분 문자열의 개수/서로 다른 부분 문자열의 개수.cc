#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set<string> st;
    string s;
    cin >> s;

    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j <= s.size() - i; j++) {
            st.emplace(s.substr(j, i));
        }
    }

    cout << st.size() << '\n';

    return 0;
}