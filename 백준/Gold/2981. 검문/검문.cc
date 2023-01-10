#include <bits/stdc++.h>

using namespace std;

int gcd (int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n), dif(n-1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n-1; i++) {
        dif[i] = v[i+1] - v[i];
    }

    int g = dif[0];
    for (int x : dif) {
        g = gcd(g, x);
    }

    vector<int> div;
    for (int i = 2; i*i <= g; i++) {
        if (g%i == 0) {
            div.push_back(i);
            if (i*i != g) div.push_back(g/i);
        }
    }
    sort(div.begin(), div.end());
    for (int& x : div) cout << x << ' ';
    cout << g;

    return 0;
}