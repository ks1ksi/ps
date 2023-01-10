#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, i = 1;
    cin >> n;

    if (n == 1) {
        cout << 1;
        return 0;
    }

    n--;

    while (1) {
        if (n - 6*i <= 0) {
            cout << i+1;
            break;
        }
        n -= 6*i;
        i++;
    }

    return 0;
}