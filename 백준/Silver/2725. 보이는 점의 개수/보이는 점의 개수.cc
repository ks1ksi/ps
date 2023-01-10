#include <bits/stdc++.h>

using namespace std;

int gcd (int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[1001] = {0};
    arr[1] = 3;
    for (int i = 2; i < 1001; i++) {
        int cnt = arr[i-1];
        for (int j = 1; j < i+1; j++) {
            if (gcd(i, j) == 1) cnt += 2;
        }
        arr[i] = cnt;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << arr[n] << '\n';
    }

    return 0;
}