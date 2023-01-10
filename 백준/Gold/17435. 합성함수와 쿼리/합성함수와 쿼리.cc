#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 200001;

int M, Q;
int table[MAX][19]; // 2^0 ~ 2^18 (n <= 500,000)

void make_table() {
    for (int i = 1; i < 19; i++) {
        for (int j = 1; j < M+1; j++) {
            table[j][i] = table[table[j][i-1]][i-1];
        }
    }
}

int query(int n, int x) {
    for (int i = 0; i < 19; i++) {
        if (n & (1<<i)) {
            x = table[x][i];
        }
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M;
    for (int i = 1; i < M+1; i++) {
        cin >> table[i][0];
    }
    make_table();

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int n, x;
        cin >> n >> x;
        cout << query(n, x) << '\n';
    }
    
    return 0;
}