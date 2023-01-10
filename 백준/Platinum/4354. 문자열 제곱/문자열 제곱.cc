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

    while (1) {
        string s;
        cin >> s;
        if (s == ".") break;
        memset(fail, 0, sizeof(fail));
        make_fail(s);
        // for (int i = 0; i < s.length(); i++) {
        //     cout << fail[i] << ' ';
        // }
        // cout << '\n';
        if (s.length()%(s.length()-fail[s.length()-1])) cout << 1 << '\n';
        else cout << s.length()/(s.length()-fail[s.length()-1]) << '\n';
    }

    return 0;
}