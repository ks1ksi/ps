#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int N;
int arr[15][15];
int cache[15][10][1<<15];

int solve(int artist, int price, int visited) {
    if (visited == (1<<N)-1) {
        return 0;
    }

    int& ret = cache[artist][price][visited];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i < N; i++) {
        if (price > arr[artist][i]) continue;
        if (visited&(1<<i)) continue;
        ret = max(ret, solve(i, arr[artist][i], visited|(1<<i))+1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            arr[i][j] = s[j]-'0';
        }
    }
    memset(cache, -1, sizeof(cache));
    cout << solve(0, 0, 1)+1;
    return 0;
}