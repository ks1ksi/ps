#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, y, z;
    cin >> x >> y >> z;

    int res = x * y * z;
    string s = to_string(res);
    int arr[10] = {0};
    for (char c : s) {
        arr[c - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}