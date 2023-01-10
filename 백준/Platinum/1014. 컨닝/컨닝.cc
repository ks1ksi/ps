#include <bits/stdc++.h>

using namespace std;

int T, N, M, cache[10][1<<10];
int m[10]; // 각 행별로 앉을 수 없는 자리 표시

int solve(int r, int state) {
    if (r == N) return 0;

    int& ret = cache[r][state]; // 각 행별 상태를 비트로 표시
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < (1<<M); j++) { // 모든 조합 시도
            if (j&m[r]) continue; // 앉을 수 없는 자리
            bool sw = false;
            for (int k = 0; k < M; k++) { // 현재 켜져있는 비트 전부 검사
                if (j&(1<<k)) { // 해당 비트가 켜져있으면
                    // 양옆에 누구 앉아있는 경우
                    if (k>0 && j&(1<<(k-1)) || k<M-1 && j&(1<<(k+1))) {
                        sw = true;
                        break;
                    }
                    // 대각선 양쪽에 누구 앉아있는 경우
                    if (k>0 && state&(1<<(k-1)) || k<M-1 && state&(1<<(k+1))) {
                        sw = true;
                        break;
                    }
                }
            }
            // 켜져있는 비트 개수만큼 더해줌
            // 맨 위부터 아래로 점점 내려가기만 하면 됨. r+1.
            if (!sw) ret = max(ret, solve(r+1, j)+__builtin_popcount(j));
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N >> M;
        memset(m, 0, sizeof(m));
        memset(cache, -1, sizeof(cache));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                char x;
                cin >> x;
                if (x == 'x') m[i] |= (1<<j);
            }
        }
        cout << solve(0, 0) << '\n';
    }
    return 0;
}