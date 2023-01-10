#include <bits/stdc++.h>

using namespace std;

int N, MCNT = 0, ANS = 0;
bool rmc[20]; // rmc[k]: -k, rmc[k+N]: k
bool rpc[20];
int arr[10][10];
vector<pair<int, int>> vo;
vector<pair<int, int>> ve;


void solve(vector<pair<int, int>>::iterator iter, int cnt) {
    if (iter == vo.end() || iter == ve.end()) {
        MCNT = max(MCNT, cnt);
        return;
    }
    
    int row = (*iter).first;
    int col = (*iter).second;
    
    if (!rmc[row-col+N] && !rpc[row+col]) {
        rmc[row-col+N] = true;
        rpc[row+col] = true;
        solve(iter+1, cnt+1);
        rmc[row-col+N] = false;
        rpc[row+col] = false;
    }
    solve(iter+1, cnt);
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                if ((i+j)%2) {
                    vo.push_back({i, j});
                }
                else {
                    ve.push_back({i, j});
                }
            }
        }
    }
    
    auto iter = vo.begin();
    solve(iter, 0);
    ANS = MCNT;
    MCNT = 0;
    iter = ve.begin();
    solve(iter, 0);
    ANS += MCNT;
    cout << ANS;
    
    return 0;
}