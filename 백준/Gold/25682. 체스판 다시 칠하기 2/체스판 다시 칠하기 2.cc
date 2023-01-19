#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int N, M, K, psum[2001][2001][2];
bool arr[2000][2000], diff[2000][2000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char x;
            cin >> x;
            if (x == 'B') arr[i][j] = 1;
        }
    }

    bool white = true;
    for (int i = 0; i < N; i++) {
        if (M % 2 == 0) white = (!white);
        for (int j = 0; j < M; j++) {
            diff[i][j] = (white == arr[i][j]);
            white = (!white);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            psum[i][j][0] = psum[i][j-1][0] + diff[i-1][j-1];
            psum[i][j][1] = psum[i][j-1][1] + !diff[i-1][j-1];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            psum[i][j][0] += psum[i-1][j][0];
            psum[i][j][1] += psum[i-1][j][1];
        }
    }

    int ans = 1e9;
    for (int i = 0; i <= N-K; i++) {
        for (int j = 0; j <= M-K; j++) {
            ans = min(ans, psum[i+K][j+K][0] - psum[i+K][j][0] - psum[i][j+K][0] + psum[i][j][0]);
            ans = min(ans, psum[i+K][j+K][1] - psum[i+K][j][1] - psum[i][j+K][1] + psum[i][j][1]);
        }
    }

    cout << ans;

    return 0;
}