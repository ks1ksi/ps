#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[2000];
int cache[2000][2000];

int solve(int start, int end) {
    if (start == end) return 1;
    if (end - start == 1 && arr[start] == arr[end]) return 1;

    int& ret = cache[start][end];
    if (ret != -1) return ret;

    ret = (arr[start] == arr[end]) && solve(start+1, end-1);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    memset(cache, -1, sizeof(cache));
    int s, e;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> s >> e;
        cout << solve(s-1, e-1) << '\n';
    }
    return 0;
}