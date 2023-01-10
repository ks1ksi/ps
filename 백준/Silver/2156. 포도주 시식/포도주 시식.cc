#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 10001;
int N, arr[MAX], cache[MAX][3];

int solve(int cur, int cnt) {
    if (cur > N) return 0;

    int& ret = cache[cur][cnt];
    if (ret != -1) return ret;

    ret = max(ret, solve(cur+1, 0));
    if (cnt < 2) ret = max(ret, solve(cur+1, cnt+1)+arr[cur]);

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

    cout << solve(0, 0);

    return 0;
}