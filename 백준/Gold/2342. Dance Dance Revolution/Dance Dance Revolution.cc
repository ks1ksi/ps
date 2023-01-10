#include <bits/stdc++.h>

using namespace std;

int arr[100000];
int cache[5][5][100000];

int get_cost(int from, int to) {
    if (from == 0) {
        if (to == 0) return 1;
        else return 2;
    }
    else {
        if (from == to) return 1;
        else if (from%2 == to%2) return 4;
        else return 3;
    }
}

int solve(pair<int, int> pos, int cur, int end) {
    if (cur == end) return 0;

    int left = pos.first;
    int right = pos.second;
    int& ret = cache[left][right][cur];
    if (ret != -1) return ret;

    ret = 987654321;
    ret = min(ret, solve({arr[cur], right}, cur+1, end) + get_cost(left ,arr[cur]));
    ret = min(ret, solve({left, arr[cur]}, cur+1, end) + get_cost(right, arr[cur]));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x = -1, cnt = 0;

    while (x != 0) {
        cin >> x;
        arr[cnt++] = x;
    }

    memset(cache, -1, sizeof(cache));
    cout << solve({0, 0}, 0, cnt-1);

    return 0;
}