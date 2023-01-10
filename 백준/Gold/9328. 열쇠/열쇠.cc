#include <bits/stdc++.h>

using namespace std;

typedef struct _data {
    int y, x;
} Data;

int T, N, M;
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
char m[100][100];
int visited[100][100];

int solve(vector<pair<int, int>> ent, int key) {
    if (ent.empty()) return 0;
    int ret = 0;
    queue<Data> q;
    q.push({-10, -10});
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (m[ny][nx] == '*') continue;
            if (visited[ny][nx] == key) continue;
            
            if (m[ny][nx] >= 'a' && m[ny][nx] <= 'z') {
                if (!(key&1<<m[ny][nx]-'a')) {
                    memset(visited, 0, sizeof(visited));
                }
                visited[ny][nx] = key;
                q.push({ny, nx});
                key = key|(1<<m[ny][nx]-'a');
            }
            else if (m[ny][nx] >= 'A' && m[ny][nx] <= 'Z') {
                if (key&(1<<m[ny][nx]-'A')) {
                    visited[ny][nx] = key;
                    q.push({ny, nx});
                }
            }
            else if (m[ny][nx] == '$') {
                ret += 1;
                m[ny][nx] = '.';
                visited[ny][nx] = key;
                q.push({ny, nx});
            }
            else {
                visited[ny][nx] = key;
                q.push({ny, nx});
            }
        }
        for (auto p : ent) {
            int ny = p.first;
            int nx = p.second;
            
            if (visited[ny][nx] == key) continue;
            
            if (m[ny][nx] >= 'a' && m[ny][nx] <= 'z') {
                if (!(key&1<<m[ny][nx]-'a')) {
                    memset(visited, 0, sizeof(visited));
                }
                visited[ny][nx] = key;
                q.push({ny, nx});
                key = key|(1<<m[ny][nx]-'a');
            }
            else if (m[ny][nx] >= 'A' && m[ny][nx] <= 'Z') {
                if (key&(1<<m[ny][nx]-'A')) {
                    visited[ny][nx] = key;
                    q.push({ny, nx});
                }
            }
            else if (m[ny][nx] == '$') {
                ret += 1;
                m[ny][nx] = '.';
                visited[ny][nx] = key;
                q.push({ny, nx});
            }
            else {
                visited[ny][nx] = key;
                q.push({ny, nx});
            }
            
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        memset(visited, -1, sizeof(visited));
        vector<pair<int, int>> v;
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> m[i][j];
                if (i == 0 || i == N-1 || j == 0 || j == M-1) {
                    if (m[i][j] != '*') {
                        v.push_back({i, j});
                    }
                }
            }
        }
        int k = 0;
        string s;
        cin >> s;
        for (char x : s) {
            if (x != '0') {
                k = k|(1<<(x-'a'));
            }
        }
        cout << solve(v, k) << '\n';
        memset(m, 0, sizeof(m));
        memset(visited, -1, sizeof(visited));
    }
    
    
    return 0;
}