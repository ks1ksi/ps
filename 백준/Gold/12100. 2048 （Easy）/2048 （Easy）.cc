#include <bits/stdc++.h>

using namespace std;

int N, MAX = 0;
int board[20][20];

void pushleft(int v[][20]) { // left push
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (v[i][j]) {
                int tmpj = j;
                while (tmpj && !v[i][tmpj-1]) {
                    swap(v[i][tmpj-1], v[i][tmpj]);
                    tmpj--;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-1; j++) {
            // merge
            if (v[i][j] && v[i][j+1] && v[i][j] == v[i][j+1]) {
                v[i][j] *= 2;
                v[i][j+1] = 0;
                int tmpj = j+1;
                while (tmpj < N-1) {
                    swap(v[i][tmpj], v[i][tmpj+1]);
                    tmpj++;
                }
            }
        }
    }
}

void rotate(int v[][20], int nv[][20]) { // cw
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            nv[j][N-1-i] = v[i][j];
        }
    }
}

void solve(int cnt, int v[][20]) {
    int curmax = 0;
    for (int i = 0; i < N; i++) {
        curmax = max(curmax, *max_element(v[i], v[i]+21));
    }
    if (curmax*(int)pow(2, 10-cnt) < MAX) {
        return;
    }
    if (cnt == 5) {
        MAX = max(MAX, curmax);
        return;
    }

    int varr[4][20][20] = {};
    rotate(v, varr[0]);
    for (int i = 1; i < 4; i++) {
        rotate(varr[i-1], varr[i]);
    }    
    for (int i = 0; i < 4; i++) {
        pushleft(varr[i]);
        solve(cnt+1, varr[i]);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    solve(0, board);
    cout << MAX;

    return 0;
}
