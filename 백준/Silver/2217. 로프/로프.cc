#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    v = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int ans = 0;
    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        ans = max(ans, v[i]*(N-i));
    }

    cout << ans;
    
    return 0;
}