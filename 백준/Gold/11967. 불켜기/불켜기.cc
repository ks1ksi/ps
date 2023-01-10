#include <bits/stdc++.h>

using namespace std;

int N, M, ANS = 1;
bool visited[101][101];
bool light[101][101];
bool available[101][101];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
vector<pair<int, int>> graph[101][101];
queue<pair<int, int>> q;

bool check_safe(int y, int x) {
    return (y > 0 && y <= N && x > 0 && x <= N);
}

void bfs() {
    visited[1][1] = true;
    available[1][1] = true;
    light[1][1] = true;
    q.push({1, 1});
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for (auto l : graph[y][x]) {
            if (!light[l.first][l.second]) {
                light[l.first][l.second] = true;
                ANS++;
                if (available[l.first][l.second]) {
                    visited[l.first][l.second] = true;
                    q.push({l.first, l.second});
                    //cout << "Teleport " << l.first << ' ' << l.second << '\n';
                }
            }
        }
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!check_safe(ny, nx)) continue;
            else if (visited[ny][nx]) continue;
            else if (!light[ny][nx]) {
                available[ny][nx] = true;
            }
            else {
                available[ny][nx] = true;
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int x, y, a, b;
    while (M--) {
        cin >> x >> y >> a >> b;
        graph[x][y].push_back({a, b});
    }
    
    bfs();
    
    // for(int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << available[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    cout << ANS << '\n';
    
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << i << ", " << j << ": \n";
    //          for (auto x : graph[i][j]) {
    //             cout << x.first << ' ' << x.second << '\n';
    //         }
    //         cout << '\n';
    //     }
    // }
    
    return 0;
}


