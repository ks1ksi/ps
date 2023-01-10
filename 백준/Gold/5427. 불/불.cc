#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int maze_j[1001][1001] = {};
        int maze_f[1001][1001] = {};
        int r, c;
        queue<pair<int, int>> jq;
        queue<pair<int, int>> fq;
        //input
        cin >> c >> r;
        for (int row = 0; row < r; row++) {
            string input;
            cin >> input;
            for (int col = 0; col < c; col++) {
                if (input[col] == '#') {
                    maze_j[row][col] = -1;
                    maze_f[row][col] = -1;
                }
                else if (input[col] == '@') {
                    maze_j[row][col] = 1;
                    jq.push({row, col});
                }
                else if (input[col] == '*') {
                    maze_f[row][col] = 1;
                    fq.push({row, col});
                }
            }
        }
        
        
        // bfs(fire)
        while (!fq.empty()) {
            int sr = fq.front().first;
            int sc = fq.front().second;
            fq.pop();
            
            for (int i = 0; i < 4; i++) {
                int nr = sr + dy[i];
                int nc = sc + dx[i];
                if (nr >= r || nc >= c || nr < 0 || nc < 0) {
                    continue;
                }
                else if (maze_f[nr][nc] != 0) {
                    continue;
                }
                else {
                    maze_f[nr][nc] = maze_f[sr][sc] + 1;
                    fq.push({nr, nc});
                }
            }
        }
        
        // bfs(jihun)
        bool imp = true;
        while (!jq.empty()) {
            int sr = jq.front().first;
            int sc = jq.front().second;
            if (sr == 0 || sr == r - 1 || sc == 0 || sc == c - 1) {
                cout << maze_j[sr][sc] << '\n';
                imp = false;
                break;
            } 
            jq.pop();
            
            for (int i = 0; i < 4; i++) {
                int nr = sr + dy[i];
                int nc = sc + dx[i];
                if (nr >= r || nc >= c || nr < 0 || nc < 0) {
                    continue;
                }
                else if (maze_j[nr][nc] != 0) {
                    continue;
                }
                // check fire
                else if (maze_f[nr][nc] <= maze_j[sr][sc] + 1 && maze_f[nr][nc] != 0) {
                    continue;
                }
                else {
                    maze_j[nr][nc] = maze_j[sr][sc] + 1;
                    jq.push({nr, nc});
                }
            }
        }
        
        if (imp) {
            cout << "IMPOSSIBLE\n";
        }
    
        // print
        // for (int row = 0; row < r; row++) {
        //     for (int col = 0; col < c; col++) {
        //         cout << maze_j[row][col] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        // for (int row = 0; row < r; row++) {
        //     for (int col = 0; col < c; col++) {
        //         cout << maze_f[row][col] << ' ';
        //     }
        //     cout << '\n';
        // }        
    }
    return 0;
}