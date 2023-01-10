#include <bits/stdc++.h>

using namespace std;

int N;
string S;
vector<string> v;

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

int cal (string& s) {
    int ret = 1;
    char op = '*';

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            string sub = "";
            i++;
            while (s[i] != ')') {
                sub += s[i];
                i++;
            }
            int val = cal(sub);
            if (op == '+') {
                ret += val;
            }
            else if (op == '-') {
                ret -= val;
            }
            else if (op == '*') {
                ret *= val;
            }
        }
        else if ('0' <= s[i] && s[i] <= '9') {
            if (op == '+') {
                ret += s[i]-'0';
            }
            else if (op == '-') {
                ret -= s[i]-'0';
            }
            else if (op == '*') {
                ret *= s[i]-'0';
            }
        }
        else {
            op = s[i];
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    make("", 0, 0);
    int m = INT_MIN;
    for (auto& s : v) {
        // cout << s << '\n';
        // cout << cal(s) << '\n';
        m = max(m, cal(s));
    }
    cout << m;

    return 0;
}