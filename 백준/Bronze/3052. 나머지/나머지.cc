#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[42] = {0};
    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        arr[x % 42]++;
    }

    int ans = 0;
    for (int i = 0; i < 42; i++) {
        if (arr[i]) ans++;
    }
    cout << ans;

    return 0;
}