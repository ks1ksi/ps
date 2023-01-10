#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, a, b, ans = 1e9;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a < b) ans = min(ans, b);
    }

    if (ans == 1e9) cout << -1;
    else cout << ans;

    return 0;
}