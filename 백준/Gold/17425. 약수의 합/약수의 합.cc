#include <bits/stdc++.h>

using namespace std;

long long arr[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    arr[1] = 1;
    for (int i = 2; i < 1000001; i++) {
        arr[i] += arr[i-1];
        arr[i] += i+1;
        for (int j = i+i; j < 1000001; j+=i) {
            arr[j] += i;
        }
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