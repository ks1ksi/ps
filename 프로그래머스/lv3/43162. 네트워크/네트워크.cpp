#include <string>
#include <vector>

using namespace std;

bool visited[201];

void f(int cur, int n, vector<vector<int>>& v) {
    visited[cur] = true;
    for (int i = 0; i < n; i++) {
        if (v[cur][i] && !visited[i]) f(i, n, v);
    }
}

int solution(int n, vector<vector<int>> cpt) {
    int ans = 0;
    
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ans++;
            f(i, n, cpt);
        }
    }
    
    return ans;
}