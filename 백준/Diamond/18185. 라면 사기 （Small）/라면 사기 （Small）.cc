#include <bits/stdc++.h>

using namespace std;

int N, B = 3, C = 2, ANS = 0;
vector<int> v, cnt; // cnt: B+C

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    v = vector<int>(N);
    cnt = vector<int>(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    ANS += B*v[0];

    for (int i = 1; i < N; i++) {
        int m = min(v[i], v[i-1]); // B -> B+C
        v[i] -= m;
        cnt[i] += m;
        ANS += C*m;

        m = min(v[i], cnt[i-1]); // B+C -> B+2C
        v[i] -= m;
        ANS += C*m;

        ANS += B*v[i]; // B
    }

    cout << ANS;

    return 0;
}