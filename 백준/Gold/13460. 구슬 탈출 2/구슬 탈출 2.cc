#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> v(n, vector<char>(m));
    for (auto& vec : v) {
        for (auto& c : vec) {
            cin >> c;
        }
    }

    int ri, rj, bi, bj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'R') {
                ri = i;
                rj = j;
            }
            else if (v[i][j] == 'B') {
                bi = i;
                bj = j;
            }
        }
    }

    queue<tuple<int, int, int, int, int>> q;
    bool visited[10][10][10][10] = {0};
    q.emplace(ri, rj, bi, bj, 0);
    visited[ri][rj][bi][bj] = 1;
    bool sw = 1;
    while (!q.empty()) {
        auto [ry, rx, by, bx, t] = q.front();
        q.pop();

        if (t >= 10) {
            cout << -1 << '\n';
            sw = 0;
            break;
        }

        int nry, nrx, nby, nbx;

        // x up
        if (bx > rx) { // 파란구슬 먼저
            bool rc = 0, bc = 0;
            nbx = bx, nrx = rx;

            // 파란구슬 움직이기
            while (nbx+1 < m && v[by][nbx+1] != '#' && v[by][nbx+1] != 'O') {
                nbx++;
            }
            if (v[by][nbx+1] == 'O') {
                nbx = -1;
                bc = 1;
            }

            // 빨간구슬 움직이기
            while (!(ry == by && nrx+1 == nbx) && nrx+1 < m && v[ry][nrx+1] != '#' && v[ry][nrx+1] != 'O') {
                nrx++;
            }
            if (v[ry][nrx+1] == 'O') {
                nrx = -1;
                rc = 1;
            }

            // 빨간구슬만 들어간 경우
            if (rc && !bc) {
                cout << t + 1 << '\n';
                sw = 0;
                break;
            }

            //  둘 다 들어가지 못한 경우
            else if (!rc && !bc) {
                if (!visited[ry][nrx][by][nbx]) {
                    q.emplace(ry, nrx, by, nbx, t+1);
                    visited[ry][nrx][by][nbx] = 1;
                }
            }
        }
        else { // 빨간구슬 먼저
            bool rc = 0, bc = 0;
            nbx = bx, nrx = rx;

            // 빨간구슬 움직이기
            while (nrx+1 < m && v[ry][nrx+1] != '#' && v[ry][nrx+1] != 'O') {
                nrx++;
            }
            if (v[ry][nrx+1] == 'O') {
                nrx = -1;
                rc = 1;
            }

            // 파란구슬 움직이기
            while (!(ry == by && nrx == nbx+1) && nbx+1 < m && v[by][nbx+1] != '#' && v[by][nbx+1] != 'O') {
                nbx++;
            }
            if (v[by][nbx+1] == 'O') {
                nbx = -1;
                bc = 1;
            }

            // 빨간구슬만 들어간 경우
            if (rc && !bc) {
                cout << t + 1 << '\n';
                sw = 0;
                break;
            }

            // 둘 다 들어가지 못한 경우
            else if (!rc && !bc) {
                if (!visited[ry][nrx][by][nbx]) {
                    q.emplace(ry, nrx, by, nbx, t+1);
                    visited[ry][nrx][by][nbx] = 1;
                }
            }
        }

        // x down
        if (bx < rx) { // 파란구슬 먼저
            bool rc = 0, bc = 0;
            nbx = bx, nrx = rx;

            // 파란구슬 움직이기
            while (nbx-1 >= 0 && v[by][nbx-1] != '#' && v[by][nbx-1] != 'O') {
                nbx--;
            }
            if (v[by][nbx-1] == 'O') {
                nbx = -1;
                bc = 1;
            }

            // 빨간구슬 움직이기
            while (!(ry == by && nrx-1 == nbx) && nrx-1 < m && v[ry][nrx-1] != '#' && v[ry][nrx-1] != 'O') {
                nrx--;
            }
            if (v[ry][nrx-1] == 'O') {
                nrx = -1;
                rc = 1;
            }

            // 빨간구슬만 들어간 경우
            if (rc && !bc) {
                cout << t + 1 << '\n';
                sw = 0;
                break;
            }

            //  둘 다 들어가지 못한 경우
            else if (!rc && !bc) {
                if (!visited[ry][nrx][by][nbx]) {
                    q.emplace(ry, nrx, by, nbx, t+1);
                    visited[ry][nrx][by][nbx] = 1;
                }
            }
        }
        else { // 빨간구슬 먼저
            bool rc = 0, bc = 0;
            nbx = bx, nrx = rx;

            // 빨간구슬 움직이기
            while (nrx-1 >= 0 && v[ry][nrx-1] != '#' && v[ry][nrx-1] != 'O') {
                nrx--;
            }
            if (v[ry][nrx-1] == 'O') {
                nrx = -1;
                rc = 1;
            }

            // 파란구슬 움직이기
            while (!(ry == by && nrx == nbx-1) && nbx-1 < m && v[by][nbx-1] != '#' && v[by][nbx-1] != 'O') {
                nbx--;
            }
            if (v[by][nbx-1] == 'O') {
                nbx = -1;
                bc = 1;
            }

            // 빨간구슬만 들어간 경우
            if (rc && !bc) {
                cout << t + 1 << '\n';
                sw = 0;
                break;
            }

            // 둘 다 들어가지 못한 경우
            else if (!rc && !bc) {
                if (!visited[ry][nrx][by][nbx]) {
                    q.emplace(ry, nrx, by, nbx, t+1);
                    visited[ry][nrx][by][nbx] = 1;
                }
            }
        }

        // y up
        if (by > ry) { // 파란구슬 먼저
            bool rc = 0, bc = 0;
            nby = by, nry = ry;

            // 파란구슬 움직이기
            while (nby+1 < n && v[nby+1][bx] != '#' && v[nby+1][bx] != 'O') {
                nby++;
            }
            if (v[nby+1][bx] == 'O') {
                nby = -1;
                bc = 1;
            }

            // 빨간구슬 움직이기
            while (!(nry+1 == nby && rx == bx) && nry+1 < n && v[nry+1][rx] != '#' && v[nry+1][rx] != 'O') {
                nry++;
            }
            if (v[nry+1][rx] == 'O') {
                nry = -1;
                rc = 1;
            }

            // 빨간구슬만 들어간 경우
            if (rc && !bc) {
                cout << t + 1 << '\n';
                sw = 0;
                break;
            }

            //  둘 다 들어가지 못한 경우
            else if (!rc && !bc) {
                if (!visited[nry][rx][nby][bx]) {
                    q.emplace(nry, rx, nby, bx, t+1);
                    visited[nry][rx][nby][bx] = 1;
                }
            }
        }
        else { // 빨간구슬 먼저
            bool rc = 0, bc = 0;
            nby = by, nry = ry;

            // 빨간구슬 움직이기
            while (nry+1 < n && v[nry+1][rx] != '#' && v[nry+1][rx] != 'O') {
                nry++;
            }
            if (v[nry+1][rx] == 'O') {
                nry = -1;
                rc = 1;
            }

            // 파란구슬 움직이기
            while (!(nry == nby+1 && rx == bx) && nby+1 < n && v[nby+1][bx] != '#' && v[nby+1][bx] != 'O') {
                nby++;
            }
            if (v[nby+1][bx] == 'O') {
                nby = -1;
                bc = 1;
            }

            // 빨간구슬만 들어간 경우
            if (rc && !bc) {
                cout << t + 1 << '\n';
                sw = 0;
                break;
            }

            //  둘 다 들어가지 못한 경우
            else if (!rc && !bc) {
                if (!visited[nry][rx][nby][bx]) {
                    q.emplace(nry, rx, nby, bx, t+1);
                    visited[nry][rx][nby][bx] = 1;
                }
            }
        }

        // y down
        if (by < ry) { // 파란구슬 먼저
            bool rc = 0, bc = 0;
            nby = by, nry = ry;

            // 파란구슬 움직이기
            while (nby-1 >= 0 && v[nby-1][bx] != '#' && v[nby-1][bx] != 'O') {
                nby--;
            }
            if (v[nby-1][bx] == 'O') {
                nby = -1;
                bc = 1;
            }

            // 빨간구슬 움직이기
            while (!(nry-1 == nby && rx == bx) && nry-1 < n && v[nry-1][rx] != '#' && v[nry-1][rx] != 'O') {
                nry--;
            }
            if (v[nry-1][rx] == 'O') {
                nry = -1;
                rc = 1;
            }

            // 빨간구슬만 들어간 경우
            if (rc && !bc) {
                cout << t + 1 << '\n';
                sw = 0;
                break;
            }

            //  둘 다 들어가지 못한 경우
            else if (!rc && !bc) {
                if (!visited[nry][rx][nby][bx]) {
                    q.emplace(nry, rx, nby, bx, t+1);
                    visited[nry][rx][nby][bx] = 1;
                }
            }
        }
        else { // 빨간구슬 먼저
            bool rc = 0, bc = 0;
            nby = by, nry = ry;

            // 빨간구슬 움직이기
            while (nry-1 >= 0 && v[nry-1][rx] != '#' && v[nry-1][rx] != 'O') {
                nry--;
            }
            if (v[nry-1][rx] == 'O') {
                nry = -1;
                rc = 1;
            }

            // 파란구슬 움직이기
            while (!(nry == nby-1 && rx == bx) && nby-1 < n && v[nby-1][bx] != '#' && v[nby-1][bx] != 'O') {
                nby--;
            }
            if (v[nby-1][bx] == 'O') {
                nby = -1;
                bc = 1;
            }

            // 빨간구슬만 들어간 경우
            if (rc && !bc) {
                cout << t + 1 << '\n';
                sw = 0;
                break;
            }

            //  둘 다 들어가지 못한 경우
            else if (!rc && !bc) {
                if (!visited[nry][rx][nby][bx]) {
                    q.emplace(nry, rx, nby, bx, t+1);
                    visited[nry][rx][nby][bx] = 1;
                }
            }
        }
    }

    if (sw) {
        cout << -1 << '\n';
    }

    return 0;
}