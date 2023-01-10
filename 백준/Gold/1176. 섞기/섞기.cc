#include <bits/stdc++.h>

using namespace std;

#define int long long

int N, K;
int arr[16];
int cache[16][1<<16];

int solve(int cur, int visited) {
    if (visited == (1<<N)-1) {
        return 1;
    }
    
    int& ret = cache[cur][visited];
    if (ret != -1) return ret;
    
    ret = 0;
    
    for (int i = 0; i < N; i++) {
        if (visited&(1<<i)) continue;
        if (abs(arr[cur] - arr[i]) > K) {
            ret += solve(i, visited|(1<<i));
        }
    }
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int ans = 0;    
    for (int i = 0; i < N; i++) {
        memset(cache, -1, sizeof(cache));
        ans += solve(i, (1<<i));
    }
    cout << ans;
    return 0;
}
