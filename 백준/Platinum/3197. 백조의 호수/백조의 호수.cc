#include <bits/stdc++.h>

using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
int N, M;
int arr[2000][2000];
int p[4000000];
vector<pair<int, int>> v;
vector<pair<int, int>> sv;


int find(int n) {
    if (p[n] < 0) return n;
    return p[n] = find(p[n]);
}

void Union(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if (n1 == n2) return;
    p[n1] += p[n2];
    p[n2] = n1;
}

bool check() {
    int np = find(M*v[0].first+v[0].second);
    for (auto p : v) {
        if (find(M*p.first+p.second) != np) return false;
    }
    return true;
}

void printmap() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

int bfs() {
    queue<pair<int, int>> q;

    for (auto p : sv) {
        q.push({p.first, p.second});
        for (int i = 0; i < 4; i++) {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];
            if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;
            if (arr[ny][nx] != 0) Union(M*ny+nx, M*p.first+p.second);
        }
    }

    // printmap();
    if (check()) return 0;

    int year = 1;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int y = cur.first;
        int x = cur.second;
        if (year != arr[y][x]) {
            // printmap();
            if (check()) return year;
            year++;
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;
            if (arr[ny][nx] != 0) continue;
            arr[ny][nx] = arr[y][x] + 1;
            for (int j = 0; j < 4; j++) {
                int nny = ny + dy[j];
                int nnx = nx + dx[j];
                if (nny >= N || nny < 0 || nnx >= M || nnx < 0) continue;
                if (arr[nny][nnx] != 0) {
                    Union(M*nny+nnx, M*ny+nx);
                }
            }
            q.push({ny, nx});
        }
    }
    return year;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char x;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> x;
            if (x == 'L') {
                arr[i][j] = 1;
                v.push_back({i, j});
                sv.push_back({i, j});
            }
            else if (x == 'X') {
                arr[i][j] = 0;
            }
            else if (x == '.') {
                arr[i][j] = 1;
                sv.push_back({i, j});
            }
        }
    }

    memset(p, -1, sizeof(p));
    cout << bfs();
    return 0;
}