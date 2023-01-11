#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K; // nm, mk
    cin >> N >> M;
    vector<vector<int>> v1(N, vector<int>(M));

    for (auto& vec: v1) {
        for (auto& x : vec) {
            cin >> x;
        }
    }

    cin >> M >> K;
    vector<vector<int>> v2(M, vector<int>(K));

    for (auto& vec: v2) {
        for (auto& x : vec) {
            cin >> x;
        }
    }
    
    vector<vector<int>> v3(N, vector<int>(K));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < M; k++) {
                v3[i][j] += v1[i][k] * v2[k][j];
            }
        }
    }

    for (auto& vec : v3) {
        for (auto x : vec) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}