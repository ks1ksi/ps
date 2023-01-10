#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int M, N;
int arr[501][501];
int cache[501][501];

int solve(int y, int x) {
    if (y == M-1 && x == N-1) return 1;

    int& ret = cache[y][x];
    if (ret != -1) return ret;
    ret = 0;

    int cur = arr[y][x];

    if (y < M-1 && cur > arr[y+1][x]) ret += solve(y+1, x);
    if (x < N-1 && cur > arr[y][x+1]) ret += solve(y, x+1);
    if (y > 0 && cur > arr[y-1][x]) ret += solve(y-1, x);
    if (x > 0 && cur > arr[y][x-1]) ret += solve(y, x-1);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    memset(cache, -1, sizeof(cache));
    cout << solve(0 ,0);

    return 0;
}