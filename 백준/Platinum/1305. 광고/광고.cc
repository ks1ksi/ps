#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 1e6+1;
int fail[MAX];

void make_fail(string& s) {
    int begin = 1, match = 0;
    while (begin + match < s.length()) {
        if (s[begin+match] == s[match]) {
            match++;
            fail[begin+match-1] = match;
        }
        else {
            if (!match) begin++;
            else {
                begin += match - fail[match-1];
                match = fail[match-1];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;         
    string s;
    cin >> s;
    memset(fail, 0, sizeof(fail));
    make_fail(s);
    cout << n-fail[n-1];

    return 0;
}