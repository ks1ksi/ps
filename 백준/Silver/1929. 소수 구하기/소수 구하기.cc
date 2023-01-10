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

    for (int i = m; i < n+1; i++) {
        if (!arr[i]) cout << i << '\n';
    }

    return 0;
}