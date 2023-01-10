#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        if (!v[0] && !v[1] && !v[2]) break;
        sort(v.begin(), v.end());
        if (v[0]*v[0] + v[1]*v[1] == v[2]*v[2]) cout << "right\n";
        else cout << "wrong\n";
    }

    return 0;
}