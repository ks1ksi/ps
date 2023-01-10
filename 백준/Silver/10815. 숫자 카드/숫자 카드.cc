#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.emplace(x);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (st.find(x) != st.end()) cout << 1 << ' ';
        else cout << 0 << ' ';
    }

    return 0;
}