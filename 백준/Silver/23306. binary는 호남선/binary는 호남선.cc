#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, start, end;
    cin >> n;

    cout << "? " << 1 << endl;
    cin >> start;
    cout << "? " << n << endl;
    cin >> end;

    cout << "! ";
    if (start == end) cout << 0;
    else if (start < end) cout << 1;
    else cout << -1;
    cout << endl;

    return 0;
}

