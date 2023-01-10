#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    int ans = 0;
    while (n--) {
        string s;
        cin >> s;
        bool sw = 1, arr[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            if (arr[s[i] - 'a']) {
                sw = 0;
                break;
            }
            arr[s[i] - 'a'] = 1;
            while (s[i] == s[i+1]) i++;
        }
        if (sw) ans++;
    }

    cout << ans;

    return 0;
}