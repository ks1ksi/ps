#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    map<int, string> m1;
    map<string, int> m2;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        m1.emplace(i, s);
        m2.emplace(s, i);
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (s[0] >= '0' && s[0] <= '9') {
            int x = stoi(s);
            cout << m1[x] << '\n';
        }
        else cout << m2[s] << '\n';
    }
    
    return 0;
}