#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    bool arr[n+1] = {0};
    arr[1] = true;
    for (int i = 2; i < n+1; i++) {
        if (!arr[i]) {
            for (int j = i+i; j < n+1; j+=i) {
                arr[j] = true;
            }
        }
    }

    int sum = 0, min;
    for (int i = n; i >= m; i--) {
        if (!arr[i]) {
            sum += i;
            min = i;
        }
    }
    if (!sum) cout << -1;
    else cout << sum << '\n' << min;

    return 0;
}