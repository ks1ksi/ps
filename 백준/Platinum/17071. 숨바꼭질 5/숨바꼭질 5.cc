#include <bits/stdc++.h>

using namespace std;

int N, K;
int visited[2][500001]; // even, odd

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    queue<vector<int>> q;
    int n, k, t;
    int ans = INT_MAX;
    cin >> N >> K;
    visited[0][N] = 1;
    q.push({N, K, 0});
    while (!q.empty()) {
        n = q.front()[0];
        k = q.front()[1];
        t = q.front()[2];
        if (n == k){
            ans = min(ans, t);
        }
        if (k > 500000) {
            break;
        }
        
        if (visited[t%2][k]) {
            ans = min(ans, t);
        }
        
        q.pop();

        if (n+1 <= 500000 && !visited[(t+1)%2][n+1]) {
            visited[(t+1)%2][n+1] = visited[t%2][n] + 1;
            q.push({n+1, k+t+1, t+1});
        }
        if (n-1 >= 0 && !visited[(t+1)%2][n-1]) {
            visited[(t+1)%2][n-1] = visited[t%2][n] + 1;
            q.push({n-1, k+t+1, t+1});
        }
        if (n*2 <= 500000 && !visited[(t+1)%2][n*2]) {
            visited[(t+1)%2][n*2] = visited[t%2][n] + 1;
            q.push({n*2, k+t+1, t+1});
        }
    }
    
    if (ans == INT_MAX) cout << -1;
    else cout << ans;
    
    return 0;
}
