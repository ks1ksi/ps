#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int ans = 0, cnt = 0;
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] == 'C') cnt++;
        if (s[i] == 'B' && cnt) {
            ans++;
            cnt--;
            s[i] = 'X';
        }
    }

    cnt = 0;
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] == 'B') cnt++;
        if (s[i] == 'A' && cnt) {
            ans++;
            cnt--;
        }
    }

    cout << ans;

    return 0;
}