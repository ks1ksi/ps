#include <bits/stdc++.h>

using namespace std;

int N;
bool arr[16][16];

int solve(int y, int x, int state) {
    if (y == N-1 && x == N-1) return 1;
    int ret = 0;
    if (state == 1) {
        if (x+1 != N && !arr[y][x+1])
            ret += solve(y, x+1, 1);
        if (x+1 != N && y+1 != N && !arr[y][x+1] && !arr[y+1][x] && !arr[y+1][x+1])
            ret += solve(y+1, x+1, 2);
    }
    else if (state == 2) {
        if (x+1 != N && !arr[y][x+1])
            ret += solve(y, x+1, 1);
        if (y+1 != N && !arr[y+1][x])
            ret += solve(y+1, x, 3);
        if (x+1 != N && y+1 != N && !arr[y][x+1] && !arr[y+1][x] && !arr[y+1][x+1])
            ret += solve(y+1, x+1, 2);
    }
    else if (state == 3) {
        if (y+1 != N && !arr[y+1][x])
            ret += solve(y+1, x, 3);
        if (x+1 != N && y+1 != N && !arr[y][x+1] && !arr[y+1][x] && !arr[y+1][x+1])
            ret += solve(y+1, x+1, 2);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    cout << solve(0, 1, 1);

    return 0;
}