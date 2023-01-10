#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    bool arr[n+1] = {0};
    arr[1] = true;
    for (int i = 2; i < n+1; i++) {
        if (!arr[i]) {
            for (int j = i; j < n+1; j+=i) {
                if (arr[j]) continue;
                arr[j] = true;
                k--;
                if (!k) {
                    cout << j;
                    return 0;
                }
            }
        }
    }

    return 0;
}