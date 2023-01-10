#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<string, int> mp;
        for (int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            mp[s2]++;
        }

        int ans = 1;
        for (auto& [k ,v] : mp) {
            ans *= (v+1);
        }

        cout << ans - 1 << '\n';

    }
    
    return 0;
}