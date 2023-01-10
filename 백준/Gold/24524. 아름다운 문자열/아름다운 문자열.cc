#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    vector<int> v(t.size());
    int ans = 0;

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < t.size(); j++) {
            if (s[i] == t[j]) {
                if (!j) v[j]++;
                else if (v[j-1] > v[j]) v[j]++;
            }
            if (v[t.size()-1]) {
                for (int k = 0; k < t.size(); k++) {
                    v[k]--;
                }
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}