#include <bits/stdc++.h>

using namespace std;

int N;

int gcd (int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i < n; i++) {
        int a = v[0];
        int b = v[i];
        if (a < b) swap(a, b);
        int g = gcd(a, b);
        cout << v[0]/g << '/' << v[i]/g << '\n';
    }

    return 0;
}