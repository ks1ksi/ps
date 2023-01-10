#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int S, L, R, N;

vector<int> vectors[4] = {{}, {1, 3, 2}, {2, 1, 1}, {2, 3, 2}};

vector<int>& getvec(int num) {
    return vectors[num];
}

vector<int> solve(int n, int k) {
    // ret[0] -> k번째 숫자
    // ret[1] ~ ret[3] -> n번 진행했을 때 k번째까지 1, 2, 3의 개수
    vector<int> ret(4);

    if (n == 0) {
        ret[0] = S;
        ret[S] = 1;
        return ret;
    }

    // if (n == 1) {
    //     vector<int>& v = getvec(S);
    //     for (int i = 0; i <= k; i++) {
    //         ret[v[i]]++;
    //     }
    //     ret[0] = v[k];
    //     return ret;
    // }

    vector<int> tmp = solve(n - 1, k / 3);
    int ln = tmp[0];
    vector<int>& v = getvec(ln);

    if (k % 3 == 0) {
        ret[0] = v[0];
        ret[v[0]]++;
        tmp[ln]--;
    }
    else if (k % 3 == 1) {
        ret[0] = v[1];
        ret[v[0]]++;
        ret[v[1]]++;
        tmp[ln]--;
    }
    else {
        ret[0] = v[2];
    }

    ret[1] += tmp[1] + tmp[2]*2;
    ret[2] += tmp[1] + tmp[2] + tmp[3]*2;
    ret[3] += tmp[1] + tmp[3];

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> L >> R >> N;

    vector<int> v1 = solve(N, R);
    vector<int> v2;
    if (L == 0) v2 = {0, 0, 0, 0};
    else v2 = solve(N, L-1);

    cout << v1[1] - v2[1] << ' ' << v1[2] - v2[2] << ' ' << v1[3] - v2[3] << '\n';

    return 0;
}