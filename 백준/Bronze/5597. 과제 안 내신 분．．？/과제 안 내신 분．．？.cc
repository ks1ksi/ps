#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[31] = {0};
    for (int i = 0; i < 28; i++) {
        int x;
        cin >> x;
        arr[x]++;
    }
    for (int i = 1; i <= 30; i++) {
        if (!arr[i]) cout << i << '\n';
    }

    return 0;
}