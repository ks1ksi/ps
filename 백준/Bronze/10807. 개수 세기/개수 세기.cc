#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, v;
    cin >> n;
    int arr[205] = {0};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[x+100]++;
    }
    cin >> v;
    cout << arr[v+100];

    return 0;
}