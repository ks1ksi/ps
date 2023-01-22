#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        
        if (s == "push") {
            int x;
            cin >> x;
            st.emplace(x);
        }
        else if (s == "pop") {
            if (st.empty()) cout << -1 << '\n';
            else {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if (s == "top") {
            if (st.empty()) cout << -1 << '\n';
            else cout << st.top() << '\n';
        }
        else if (s == "size") {
            cout << st.size() << '\n';
        }
        else if (s == "empty") {
            cout << st.empty() << '\n';
        }
    }

    return 0;
}