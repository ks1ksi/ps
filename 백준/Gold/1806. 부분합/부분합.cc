#include <bits/stdc++.h>

using namespace std;

int N, S;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int p1 = 0, p2 = 0, sum = v[0], len = 100001;
    while (p1 != N && p2 != N) {
        if (sum < S) {
            p2++;
            sum += v[p2];
        }
        else {
            len = min(len, p2-p1+1);
            if (len == 1) break;
            sum -= v[p1];
            p1++;
        }
    }
    if (len == 100001) cout << 0;
    else cout << len;

    return 0;
}