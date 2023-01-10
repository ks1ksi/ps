#include <bits/stdc++.h>

using namespace std;

int N, M, C; // gem, bag, limit
int arr[13];
int cache[11][21][1<<13]; // bag, weight, visited

int solve(int bag, int weight, int visited) {
    if (bag == M) return -1;
    if (visited == (1<<N)-1) return 0;

    int& ret = cache[bag][weight][visited];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i < N; i++) {
        if (visited&(1<<i)) continue;
        else if (arr[i] > C) continue;
        else if (weight+arr[i] > C) {
            ret = max(ret, solve(bag+1, arr[i], visited|(1<<i))+1);
        }
        else {
            ret = max(ret, solve(bag, weight+arr[i], visited|(1<<i))+1);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> C;
    for (int i = 0 ; i < N; i++) {
        cin >> arr[i];
    }
    memset(cache, -1, sizeof(cache));
    cout << solve(0, 0, 0);
    return 0;
}