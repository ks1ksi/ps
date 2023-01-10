#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int idx = -1;
    stack<int> s;
    for (int i = n-1; i >= 0; i--) {
        s.push(idx);
        if (i && v[i] != v[i-1]) idx = i+1;
    }
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }

    return 0;
}