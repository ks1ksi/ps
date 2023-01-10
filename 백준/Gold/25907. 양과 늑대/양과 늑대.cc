#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int lo = 1, hi = n, cnt;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        cout << "? " << mid << endl;
        cin >> cnt;

        if (cnt*2 > mid) lo = mid + 1;
        else if (cnt*2 < mid) hi = mid - 1;
        else {
            cout << "! " << mid << endl;
            break;
        }
    }
    
    return 0;
}