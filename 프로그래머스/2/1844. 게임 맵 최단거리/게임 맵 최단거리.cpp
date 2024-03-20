#include <vector>
#include <queue>

using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

int bfs(vector<vector<int>>& maps) {
    int n = maps.size();
    int m = maps[0].size();
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny == n || nx < 0 || nx == m) {
                continue;
            }
            if (maps[ny][nx] == 1) {
                maps[ny][nx] = maps[y][x] + 1;
                q.emplace(ny, nx);
            }
        }
    }
    
    return maps[n-1][m-1];
}

int solution(vector<vector<int>> maps) {
    int answer = bfs(maps);
    return answer == 1 ? -1 : answer;
}