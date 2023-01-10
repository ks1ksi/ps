#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int ans = 0;
    
    while (1) {
        if (N <= 0) break;
        if (N%5) {
            N -= 3;
            ans++;
        }
        else {
            ans += N/5;
            N = 0;
        }

    }
    if (N < 0) cout << -1;
    else cout << ans;

    return 0;
}