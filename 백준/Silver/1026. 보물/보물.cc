#include <bits/stdc++.h>

using namespace std;

int N;

bool comp(int a, int b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<int> a(N), b(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), comp);
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += a[i]*b[i];
    }

    cout << ans;

    return 0;
}