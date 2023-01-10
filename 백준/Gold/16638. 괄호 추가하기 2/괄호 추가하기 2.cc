#include <bits/stdc++.h>

using namespace std;

int N;
string S;
vector<string> v;
map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}};

void make(string s, int idx, int open) {
    if (idx >= N) {
        if (!open) v.push_back(s);
        return;
    }
    if (!open) {
        make(s+'('+S[idx]+S[idx+1], idx+2, 1);
        make(s+S[idx]+S[idx+1], idx+2, open);
    }
    else {
        make(s+S[idx]+')'+S[idx+1], idx+2, 0);
    }
}

int cal(string& s) {
    string pn = "";
    stack<char> op;

    for (auto c = s.begin(); c != s.end(); c++) {
        if ('0' <= *c && *c <= '9') pn += *c;

        else if(*c == '(') op.push(*c);

        else if (*c == ')') {
            while (op.top() != '(') {
                pn += op.top();
                op.pop();
            }
            op.pop();
        }

        else {
            if (op.empty() || priority[op.top()] < priority[*c]) {
                op.push(*c);
            }
            else {
                while (!op.empty() && priority[op.top()] >= priority[*c]) {
                    pn += op.top();
                    op.pop();
                }
                op.push(*c);
            }
        }
    }

    while (!op.empty()) {
        pn += op.top();
        op.pop();
    }

    stack<int> num;

    for (auto c = pn.begin(); c != pn.end(); c++) {
        if ('0' <= *c && *c <= '9') {
            num.push(*c-'0');
        }
        else {
            if (*c == '+') {
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();
                num.push(a+b);
            }
            else if (*c == '-') {
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();
                num.push(b-a);

            }
            else if (*c == '*') {
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();
                num.push(a*b);
            }
        }
    }
    // cout << pn << '\n';
    return num.top();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    make("", 0, 0);
    int m = INT_MIN;
    for (auto& s : v) {
        m = max(m, cal(s));
    }
    cout << m;

    return 0;
}