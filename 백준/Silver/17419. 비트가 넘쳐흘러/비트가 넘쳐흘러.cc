#include <bits/stdc++.h>

using namespace std;

int solve(int k, int cnt) {
    if (!k) return cnt;
    return solve(k-(k&((~k)+1)), cnt+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0;
    for (char c : s) {
        x *= 2;
        x += c-'0';
    }

    cout << solve(x, 0);

    return 0;
}