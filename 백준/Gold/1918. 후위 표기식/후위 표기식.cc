#include <bits/stdc++.h>

using namespace std;

map<char, int> priority = {{'(', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    stack<char> s;

    for (char& c : str) {
        if (isalpha(c)) {
            cout << c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (s.top() != '(') {
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            while (!s.empty() && priority[s.top()] >= priority[c]) {
                cout << s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}