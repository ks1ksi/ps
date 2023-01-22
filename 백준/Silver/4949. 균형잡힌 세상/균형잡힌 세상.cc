#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    stack<char> st;
    while (1) {
        while (st.size()) st.pop();
        getline(cin, s);
        if (s == ".") break;
        bool sw = true;
        for (auto c : s) {
            if (c == '(' || c == '[') st.emplace(c);
            else if (c == ')') {
                if (st.empty() || st.top() != '(') {
                    sw = false;
                    break;
                }
                else st.pop();
            }
            else if (c == ']') {
                if (st.empty() || st.top() != '[') {
                    sw = false;
                    break;
                }
                else st.pop();
            }
        }
        if (sw && st.empty()) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}