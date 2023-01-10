#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 100001, SZ = 30;

int N, K, M;
int table[MAX][SZ];

void make_table() {
    for (int i = 1; i < SZ; i++) {
        for (int j = 1; j < K+1; j++) {
            table[j][i] = table[table[j][i-1]][i-1];
        }
    }
}

int query(int n, int x) {
    for (int i = 0; i < SZ; i++) {
        if (n & (1<<i)) {
            x = table[x][i];
        }
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K >> M;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    for (int i = 1; i < K+1; i++) {
        cin >> table[i][0];
    }
    make_table();
    for (int x : v) {
        cout << query(M-1, x) << ' ';
    }
    return 0;
}