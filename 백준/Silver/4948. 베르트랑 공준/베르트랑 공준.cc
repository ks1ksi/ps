#include <bits/stdc++.h>

using namespace std;

int gcd (int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bool arr[1000001] = {0};
    arr[1] = true;
    for (int i = 2; i < 1000001; i++) {
        if (!arr[i]) {
            for (int j = i+i; j < 1000001; j+=i) {
                arr[j] = true;
            }
        }
    }

    while (1) {
        int n;
        cin >> n;
        if (!n) break;
        int cnt = 0;
        for (int i = n+1; i < 2*n +1; i++) {
            if (!arr[i]) ++cnt;
        }
        cout << cnt << '\n';
    }


    return 0;
}