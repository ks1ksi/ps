#include <bits/stdc++.h>

using namespace std;

int N, S, CNT = 0;

void solve(int sum, int idx, vector<int>& v) {
    if (idx == N) {
        if (sum == S) {
            CNT++;
        }
        return;
    }
    solve(sum + v[idx], idx + 1, v);
    solve(sum, idx + 1, v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    solve(0, 0, v);
    if (S == 0) CNT--;
    cout << CNT;
        
    return 0;
}
