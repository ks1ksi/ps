#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, L, I;

int dp[32][32]; // max, cur
int sum[32][32];

void print_ans(int idx) {
    idx--;
    int one = L;
    for (int i = N-1; i >= 0; i--) {
        if (sum[i][min(one, i)] <= idx) {
            cout << 1;
            idx -= sum[i][min(one, i)];
            one--;
        }
        else cout << 0;
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> L >> I;

    dp[1][0] = 1;
    dp[1][1] = 1;
    sum[0][0] = 1;
    sum[1][0] = 1;
    sum[1][1] = 2;

    for (int i = 2; i < N+1; i++) {
        sum[i][0] = sum[i-1][0];
        for (int j = 0; j < min(i+1, L+1); j++) {
            if (j>0) dp[i][j] += dp[i-1][j-1]; // 1
            dp[i][j] += dp[i-1][j]; // 0
            if (j>0) sum[i][j] = sum[i][j-1] + dp[i][j];
        }
    }

    print_ans(I);

    // for (int i = 1; i < N+1; i++) {
    //     for (int j = 0; j < L+1; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // for (int i = 1; i < I+1; i++) {
    //     print_ans(i);
    // }


    // for (int i = 1; i < N+1; i++) {
    //     for (int j = 0; j < L+1; j++) {
    //         cout << sum[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}