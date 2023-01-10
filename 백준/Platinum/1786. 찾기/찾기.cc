#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 1e6+10;
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
                // 지금까지 일치한 접두사의 실패함수로
                // 다음 begin, match 찾기
                begin += match - fail[match-1];
                match = fail[match-1];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    vector<int> v;

    getline(cin, s1);
    getline(cin, s2);
    make_fail(s2);

    int begin = 0, match = 0;
    while (begin + match < s1.length()) {
        if (match < s2.length() && s1[begin+match] == s2[match]) {
            match++;
            if (match == s2.length()) v.push_back(begin+1);
        }
        else {
            if (!match) begin++;
            else {
                begin += match - fail[match-1];
                match = fail[match-1];
            }
        }
    }
    cout << v.size() << '\n';
    for (int x : v) {
        cout << x << ' ';
    }

    return 0;
}