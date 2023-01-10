#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    int n, m;
    cin >> n >> m;
    set<string> st;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        st.emplace(s);
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (st.find(s) != st.end()) cnt++;
    }

    cout << cnt;

    return 0;
}