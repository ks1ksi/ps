#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 1e6+1;
int fail[MAX];

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}

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
    string s, s2;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        s += c;
    }
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        s2 += c;
    }
    s2 += s2;
    memset(fail, 0, sizeof(fail));
    make_fail(s);

    vector<int> v;
    // s2에서 s찾기
    int begin = 1, match = 0;
    while (begin + match < s2.length()) {
        if (match < s.length() && s2[begin+match] == s[match]) {
            match++;
            if (match == s.length()) v.push_back(begin);
        }
        else {
            if (!match) begin++;
            else {
                begin += match - fail[match-1];
                match = fail[match-1];
            }
        }
    }

    cout << v.size()/gcd(v.size(), n) << '/' << n/gcd(v.size(), n);

    return 0;
}