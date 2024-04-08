#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

// 0: n
// 1: e
// 2: s
// 3: w
// 4: u
// 5: d
int dice[6] = {2, 3, 5, 4, 1, 6};

// 동 남 서 북
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int n, m, k;

void rotate_right() {
    // u, e, d, w가 한바퀴 돌아야 함
    int tmp = dice[4];
    dice[4] = dice[3];
    dice[3] = dice[5];
    dice[5] = dice[1];
    dice[1] = tmp;
}

void rotate_up() {
    // u, n, d, s가 한바퀴 돌아야 함
    int tmp = dice[4];
    dice[4] = dice[2];
    dice[2] = dice[5];
    dice[5] = dice[0];
    dice[0] = tmp;
}

void rotate(int d) {
    if (d == 0) {
        rotate_right();
        return;
    }

    if (d == 1) {
        for (int i = 0; i < 3; i++) {
            rotate_up();
        }
        return;
    }

    if (d == 2) {
        for (int i = 0; i < 3; i++) {
            rotate_right();
        }
        return;
    }

    if (d == 3) {
        rotate_up();
        return;
    }
}

int cal_score(int y, int x, vector<vector<int>>& arr) {
    vector<vector<int>> visited(arr.size(), vector<int>(arr[0].size()));

    queue<pair<int, int>> q;
    int cnt = 1;
    visited[y][x] = 1;
    q.emplace(y, x);
    while (!q.empty()) {
        auto [yy, xx] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = yy + dy[i], nx = xx + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (visited[ny][nx]) continue;
            if (arr[ny][nx] != arr[y][x]) continue;
            cnt++;
            q.emplace(ny, nx);
            visited[ny][nx] = 1;
        }
    }

    return cnt * arr[y][x];
}

// 주사위 아랫면, 지도 숫자, 방향
void update_d(int btm, int val, int& d) {
    if (btm > val) d = (d + 1) % 4;
    if (btm < val) d = (d + 3) % 4;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    vector<vector<int>> arr(n, vector<int>(m));
    for (auto& v : arr) {
        for (auto& x : v) {
            cin >> x;
        }
    }

    int score = 0;
    int y = 0, x = 0, d = 0;
    while (k--) {
        // d 방향으로 움직일 수 있는지 확인
        // 움직이지 못한다면 방향 반대로 바꿔주기
        if (y + dy[d] < 0 || y + dy[d] >= n || x + dx[d] < 0 ||
            x + dx[d] >= m) {
            d = (d + 2) % 4;
        }

        y = y + dy[d];
        x = x + dx[d];
        rotate(d);
        score += cal_score(y, x, arr);
        update_d(dice[5], arr[y][x], d);
    }

    cout << score << '\n';

    return 0;
}
