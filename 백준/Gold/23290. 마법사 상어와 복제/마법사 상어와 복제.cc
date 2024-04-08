#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

// 방향 입력값 - 1 (0 ~ 7)
int ddy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int ddx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

// 상, 좌, 하, 우 순서 (사전순)
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int m, s, sx, sy;

// 반시계 방향으로 회전
void update_d(int& d) {
    if (d == 0)
        d = 7;
    else
        d -= 1;
}

// 해당 격자에 있는 물고기 세기
int count_fish(unordered_map<int, int>& um) {
    int ret = 0;
    for (auto& [d, cnt] : um) {
        ret += cnt;
    }
    return ret;
}

// 물고가기 해당 방향으로 움직일 수 있는지 확인
bool check(int y, int x, int d, vector<vector<int>>& smell) {
    int ny = y + ddy[d];
    int nx = x + ddx[d];

    if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) return false;
    if (smell[ny][nx] > 0) return false;
    if (ny == sy && nx == sx) return false;

    return true;
}

// 상어가 해당 경로로 움직였을 때 죽이는 물고기 계산
int kill_fish_count(vector<int>& moves,
                    vector<vector<unordered_map<int, int>>> fishes) {
    int cnt = 0;
    int y = sy;
    int x = sx;

    for (auto i : moves) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) {
            // 상어가 움직일 수 없는 경우 -1 반환
            return -1;
        }

        y = ny;
        x = nx;
        cnt += count_fish(fishes[y][x]);
        fishes[y][x].clear();
    }

    return cnt;
}

void print_fishes(vector<vector<unordered_map<int, int>>>& fishes) {
    for (auto& v : fishes) {
        for (auto& um : v) {
            cout << count_fish(um) << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> s;

    // y, x, d
    vector<tuple<int, int, int, int>> fv(m);

    // 냄새 2 -> 1 -> 0 표시
    vector<vector<int>> smell(4, vector<int>(4));

    // fishes[y][x] 에 d(0~7)를 바라보는 물고기가 몇마리 있는지 {방향, 마리}
    vector<vector<unordered_map<int, int>>> fishes(
        4, vector<unordered_map<int, int>>(4));

    for (auto& [y, x, d, c] : fv) {
        cin >> y >> x >> d;
        y--;
        x--;
        d--;
        c = 1;
        fishes[y][x][d]++;
    }

    cin >> sy >> sx;
    sy--;
    sx--;

    while (s--) {
        // fishes 에 있는 물고기들 방향 조건 맞춰서 한 칸 이동
        vector<vector<unordered_map<int, int>>> nf(
            4, vector<unordered_map<int, int>>(4));

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (auto p : fishes[i][j]) {
                    int dir = p.first;
                    int cnt = p.second;
                    int ny = i;
                    int nx = j;

                    int t = 8;
                    // 8방향 다 시도해도 안되면 가만히 있음
                    while (t--) {
                        if (check(i, j, dir, smell)) {
                            ny = i + ddy[dir];
                            nx = j + ddx[dir];
                            break;
                        } else {
                            update_d(dir);
                        }
                    }
                    nf[ny][nx][dir] += cnt;
                }
            }
        }
        fishes = nf;

        // 가장 많이 잡아먹는 방향 계산
        int fishcnt = -1;
        vector<int> t;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    vector<int> moves = {i, j, k};
                    int tmp = kill_fish_count(moves, fishes);
                    if (tmp > fishcnt) {
                        fishcnt = tmp;
                        t = moves;
                    }
                }
            }
        }

        // 잡아먹고 냄새 남기기
        for (auto i : t) {
            sy = sy + dy[i];
            sx = sx + dx[i];
            if (count_fish(fishes[sy][sx]) > 0) {
                fishes[sy][sx].clear();
                smell[sy][sx] = 3;
            }
        }

        // 냄새 벡터에 있는 숫자 1 감소
        for (auto& v : smell) {
            for (auto& x : v) {
                if (x) x--;
            }
        }

        // fv에 있는 물고기들 fishes에 반영
        for (auto [y, x, d, c] : fv) {
            fishes[y][x][d] += c;
        }

        // fv 비우고 fishes 내용을 fv에 반영
        fv.clear();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (auto [d, cnt] : fishes[i][j]) {
                    if (cnt) fv.emplace_back(i, j, d, cnt);
                }
            }
        }
    }

    int ans = 0;
    for (auto& v : fishes) {
        for (auto& um : v) {
            ans += count_fish(um);
        }
    }

    cout << ans << '\n';

    return 0;
}
