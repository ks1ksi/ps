#include <bits/stdc++.h>

using namespace std;

int N;

int gcd (int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int a = v[i];
                int b = v[j];
                if (a < b) swap(a, b);
                ans += gcd(a, b);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}