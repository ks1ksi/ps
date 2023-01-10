#include <bits/stdc++.h>

using namespace std;

void solve(int n, int from, int to) {
    if (n == 1) {
        cout << from << ' ' << to << '\n';
    }
    else {
        if (from == 1) {
            if (to == 2) {
                solve(n-1, 1, 3);
                cout << from << ' ' << to << '\n';
                solve(n-1, 3, 2);
            }
            else if (to == 3) {
                solve(n-1, 1, 2);
                cout << from << ' ' << to << '\n';
                solve(n-1, 2, 3);
            }
        }
        else if (from == 2) {
            if (to ==  1) {
                solve(n-1, 2, 3);
                cout << from << ' ' << to << '\n';
                solve(n-1, 3, 1);
            }
            else if (to == 3) {
                solve(n-1, 2, 1);
                cout << from << ' ' << to << '\n';
                solve(n-1, 1, 3);
            }
        }
        else if (from == 3) {
            if (to == 1) {
                solve(n-1, 3, 2);
                cout << from << ' ' << to << '\n';
                solve(n-1, 2, 1);
            }
            else if (to == 2) {
                solve(n-1, 3, 1);
                cout << from << ' ' << to << '\n';
                solve(n-1, 1, 2);
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> x;
    cout << (int)pow(2, x) - 1 << '\n';
    solve(x, 1, 3);
    
    return 0;
}
