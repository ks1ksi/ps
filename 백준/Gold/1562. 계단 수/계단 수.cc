#include <bits/stdc++.h>

using namespace std;

int N;
int dp[101][10][1<<10];

int solve(int cnt, int last, int used) {
    if (dp[cnt][last][used]) return dp[cnt][last][used];
    
    if (cnt == N) {
        if (used == (1<<10)-1) return 1;
        else return 0;
    }
    
    int ret = 0;
    if (last > 0) {
        ret += solve(cnt+1, last-1, used|(1<<last-1));
    }
    if (last < 9) {
        ret += solve(cnt+1, last+1, used|(1<<last+1));
    }
    return dp[cnt][last][used] = ret%1000000000;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    long long ans = 0;
    for (int i = 1; i < 10; i++) {
        ans += solve(1, i, 1<<i);
    }
    cout << ans%1000000000;

    return 0;
}
