#include <bits/stdc++.h>

using namespace std;

int N;
string S;
vector<string> v;
map<char, int> priority = {{'(', 0}, {'+', 1}, {'-', 1}, {'*', 2}};

void make(string s, int idx, int open) {
    if (idx == N-1) {
        s += S[idx];
        while (open--) {
            s += ')';
        }
        v.push_back(s);
        return;
    }
    if (open > N/2 - idx/2 + 1) return;

    string o = "";
    for (int i = 0; i < N/2-open; i++) {
        o += '(';
        make(s+o+S[idx]+S[idx+1], idx+2, open+o.size());
    }

    make(s+S[idx]+S[idx+1], idx+2, open);
    if (open) {
        make(s+S[idx]+')'+S[idx+1], idx+2, open-1);
    }
}

int cal(string& s) {
    string postfix = "";
    stack<char> op;

    for (auto c = s.begin(); c != s.end(); c++) {
        if ('0' <= *c && *c <= '9') postfix += *c;

        else if(*c == '(') op.push(*c);

        else if (*c == ')') {
            while (op.top() != '(') {
                postfix += op.top();
                op.pop();
            }
            op.pop();
        }

        else {
            // while (!op.empty() && priority[op.top()] >= priority[*c]) {
            //     postfix += op.top();
            //     op.pop();
            // }
            op.push(*c);
        }
    }

    while (!op.empty()) {
        postfix += op.top();
        op.pop();
    }

    stack<int> num;

    for (auto c = postfix.begin(); c != postfix.end(); c++) {
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
    // cout << postfix << '\n';
    return num.top();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    make("", 0, 0);
    int m = INT_MIN;
    // int cnt = 0;
    for (auto& s : v) {
        // cout << s << '\n';
        // cnt++;
        m = max(m, cal(s));
    }
    cout << m;

    return 0;
}