#include <bits/stdc++.h>

using namespace std;

int arr[250000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, cur = 1;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (cur == arr[i]) cur++;
    }

    cout << n - cur + 1;

    return 0;
}