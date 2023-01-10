#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v;
    int x = 2;
    while (n != 1) {
        while (n%x == 0) {
            n /= x;
            cout << x << '\n';
        }
        x++;
    }

    return 0;
}