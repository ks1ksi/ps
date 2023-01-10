#include <bits/stdc++.h>

using namespace std;

short arr[1000][300][300];
bool visited[300][300];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int N, M, T = 0;

bool check_safe(int row, int col) {
    return !(row < 0 || col < 0 || row >= N || col >= M);
}

int count_water(int t, int row, int col) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int ny = row + dy[i];
        int nx = col + dx[i];
        if (!check_safe(ny, nx)) continue;
        else if (arr[t][ny][nx] == 0) cnt++;
    }
    return cnt;
}

bool dfs(int row, int col) {
    if (visited[row][col]) return false;
    visited[row][col] = 1;

    arr[T+1][row][col] = arr[T][row][col] - count_water(T, row, col);
    if (arr[T+1][row][col] < 0) arr[T+1][row][col] = 0;
    
    for (int i = 0; i < 4; i++) {
        int ny = row + dy[i];
        int nx = col + dx[i];
        if (!check_safe(ny, nx)) continue;
        else if (visited[ny][nx] || arr[T][ny][nx] == 0) continue;
        else dfs(ny, nx);
    }
    return true;
}

int solve() {
    int time = 0;
    int cnt = 0;
    while (1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[T][i][j] != 0) {
                    if (dfs(i, j)) cnt++;
                }
            }
        }
        if (cnt >= 2) return T;
        else if (cnt == 0) return 0;
        else {
            cnt = 0;
            memset(visited, 0, sizeof(visited));
            T++;            
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[0][i][j];
            // cout << arr[0][i][j] << ' ';
        }
        // cout << '\n';
    }
    
    cout << solve() << '\n';
    
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << arr[1][i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    return 0;
}


