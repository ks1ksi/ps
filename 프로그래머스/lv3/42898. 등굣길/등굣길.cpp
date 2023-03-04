#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;
int cache[100][100], p[100][100], N, M;

int solve(int r, int c) {
    if (r == N-1 && c == M-1) {
        return 1;
    }
    
    int& ret = cache[r][c];
    if (ret != -1) return ret;
    
    ret = 0;
    if (r+1 < N && !p[r+1][c]) {
        ret += solve(r+1, c);
        ret %= MOD;
    }
    if (c+1 < M && !p[r][c+1]) {
        ret += solve(r, c+1);
        ret %= MOD;
    }
    
    return ret % MOD;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    N = n;
    M = m;
    memset(cache, -1, sizeof(cache));
    for (auto& v : puddles) {
        p[v[1]-1][v[0]-1] = 1;
    }

    int ans = solve(0, 0);
        
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << cache[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    return ans;
    
    
}