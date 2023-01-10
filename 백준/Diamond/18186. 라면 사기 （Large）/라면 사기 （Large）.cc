#include <bits/stdc++.h>

using namespace std;

int N, B, C;
long long ANS = 0;
vector<long long> v, cnt; // cnt: B+C

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> B >> C;
    v = vector<long long>(N);
    cnt = vector<long long>(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    if (B <= C) {
        for (int i = 0; i < N; i++) {
            ANS += B*v[i];
        }
    }

    else {
        ANS += B*v[0];
        for (int i = 1; i < N; i++) {
            long long m = min(v[i], v[i-1]); // B -> B+C
            v[i] -= m;
            cnt[i] += m;
            ANS += C*m;

            m = min(v[i], cnt[i-1]); // B+C -> B+2C
            v[i] -= m;
            ANS += C*m;

            ANS += B*v[i]; // B
        }
    }

    cout << ANS;

    return 0;
}