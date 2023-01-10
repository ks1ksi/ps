#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long N, sum = 0;
    cin >> N;

    for (int start = 2; start <= N; start++) {
        long long n = start;
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
        //cout << start << ' ' << ans << '\n';
        sum += ans;
    }

    cout << sum;
    
    return 0;
}