#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int dp[1001][1001] = {0};

    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
        }
    }

    cout << dp[s1.size()][s2.size()] << '\n';

    return 0;
}