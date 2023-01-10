#include <bits/stdc++.h>

using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
int N, K;
int arr[2000][2000];
int p[4000000];
vector<pair<int, int>> v;

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
    int np = find(N*v[0].first+v[0].second);
    for (auto p : v) {
        if (find(N*p.first+p.second) != np) return false;
    }
    return true;
}

int bfs() {
    queue<pair<int, int>> q;
    for (auto p : v) {
        q.push(p);
        arr[p.first][p.second] = 1;
    }
 
    for (auto p : v) {
        for (int i = 0; i < 4; i++) {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];
            if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;
            if (arr[ny][nx] > 0) Union(N*ny+nx, N*p.first+p.second);
        }
    }

    if (check()) return 0;

    int year = 1;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int y = cur.first;
        int x = cur.second;
        if (year != arr[y][x]) {
            if (check()) return year;
            year++;
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;
            if (arr[ny][nx] != 0) continue;
            arr[ny][nx] = arr[y][x] + 1;
            for (int j = 0; j < 4; j++) {
                int nny = ny + dy[j];
                int nnx = nx + dx[j];
                if (nny >= N || nny < 0 || nnx >= N || nnx < 0) continue;
                if (arr[nny][nnx] > 0) {
                    Union(N*nny+nnx, N*ny+nx);
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
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({y-1, x-1});
    }
    memset(p, -1, sizeof(p));
    cout << bfs();
    return 0;
}