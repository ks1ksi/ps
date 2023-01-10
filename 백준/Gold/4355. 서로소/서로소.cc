#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        long long n;
        cin >> n;
        if (!n) break;
        long long ans = n;
        for (long long i = 2; i*i <= n; i++) {
            if (n%i == 0) {
                ans -= ans/i;
                while (n%i == 0) n/=i;
            }
        }
        if (n != 1) {
            ans -= ans/n;
        }
        cout << ans << '\n';
    }
    
    return 0;
}