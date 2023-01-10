#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[15][15] = {0}, psum[15][15] = {0};
    for (int i = 1; i < 15; i++) {
        arr[0][i] = i;
        psum[0][i] = psum[0][i-1] + arr[0][i]; 
    }

    for (int i = 1; i < 15; i++) {
        for (int j = 1; j < 15; j++) {
            arr[i][j] = psum[i-1][j];
            psum[i][j] = psum[i][j-1] + arr[i][j];
        }
    }
    
    int t;
    cin >> t;
    while (t--) {
        int k, n;
        cin >> k >> n;
        cout << arr[k][n] << '\n';
    }

    return 0;
}