#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int sum = 0, x = 0;
    while (1) {
        cin >> x;
        if (x == -1) break;
        sum += x;
    }
    cout << sum;
    return 0;
}