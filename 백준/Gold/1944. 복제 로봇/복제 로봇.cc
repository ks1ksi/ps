#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 50, dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
int N, M;
int p[251], num[MAX][MAX], g[MAX][MAX];
char m[MAX][MAX];
vector<pair<int, pair<int, int>>> e;
pair<int, int> s;
vector<pair<int, int>> k;

int find(int n) {
    if (p[n] < 0) return n;
    return p[n] = find(p[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if (n1 == n2) return;
    p[n1] += p[n2];
    p[n2] = n1;   
}

void bfs(int r, int c) {
    memset(g, 0, sizeof(g));
    queue<pair<int, int>> q;
    q.push({r, c});
    g[r][c] = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (m[ny][nx] == '1' || g[ny][nx]) continue;
            g[ny][nx] = g[y][x] + 1;
            q.push({ny, nx});
            if (m[ny][nx] == 'K') {
                k.push_back({ny, nx});
                e.push_back({g[y][x], {num[r][c], num[ny][nx]}});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int cnt = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> m[i][j];
            if (m[i][j] == 'S') {
                s = {i, j};
            }
            if (m[i][j] == 'K') {
                num[i][j] = cnt++;
            }
        }
    }

    bfs(s.first, s.second);
    if (k.size() == M) {
        for (int i = 0; i < M; i++) {
            bfs(k[i].first, k[i].second);
        }
        sort(e.begin(), e.end());
        memset(p, -1, sizeof(p));
        int ans = 0;
        for (auto pp : e) {
            int c = pp.first;
            int a = pp.second.first;
            int b = pp.second.second;
            if (find(a) == find(b)) continue;
            merge(a, b);
            ans += c;
        }
        cout << ans << '\n';
    }
    else cout << -1 << '\n';

    return 0;
}