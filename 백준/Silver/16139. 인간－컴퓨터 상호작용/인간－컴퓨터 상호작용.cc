#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int n;
    cin >> s >> n;

    vector<vector<int>> v(200001, vector<int>(26));
    v[0][s[0]-'a']++;

    for (int i = 1; i < s.size(); i++) {
        v[i] = v[i-1];
        v[i][s[i]-'a']++;
    }
    
    while (n--) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if (l) cout << v[r][c-'a'] - v[l-1][c-'a'] << '\n';
        else cout << v[r][c-'a'] << '\n';
    }

    return 0;
}
