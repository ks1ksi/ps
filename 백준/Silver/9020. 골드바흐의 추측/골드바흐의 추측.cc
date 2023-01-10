#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

constexpr int MAX = 10001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[MAX] = {0};
    for (int i = 2; i <= sqrt(MAX); i++) {
        if (!arr[i]) {
            for (int j = i*2; j < MAX; j += i) {
                arr[j]++;
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = n/2; i >= 2; i--) {
            if (!arr[i] && !arr[n-i]) {
                cout << i << ' ' << n-i << '\n';
                break;
            }
        }
    }

    return 0;
}