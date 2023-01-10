#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0, cnt = 0;
    string str;
    cin >> str;
    string::iterator iter = str.begin();
    while (iter != str.end()) {
        if (*iter == '(') {
            if (*(iter+1) == '(') {
                cnt++;
            }
            else if (*(iter+1) == ')') {
                ans += cnt;
                iter++;
            }
        }
        else if (*iter == ')') {
            ans++;
            cnt--;
        }
        iter++;
    }

    cout << ans;
    return 0;
}