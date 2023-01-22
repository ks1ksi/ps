#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }

    int idx = 0;
    stack<int> st;
    vector<char> ans;
    for (int i = 1; i <= n; i++) {
        st.emplace(i);
        ans.emplace_back('+');
        while (st.size() && st.top() == v[idx]) {
            idx++;
            st.pop();
            ans.emplace_back('-');
        }
    }

    if (st.empty()) {
        for (auto c : ans) {
            cout << c << '\n';
        }
    }
    else cout << "NO\n";

    return 0;
}