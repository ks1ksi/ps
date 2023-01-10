#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> arr[500];
int cache[500][500];

int solve(int start, int end) {
    if (start == end) return 0;
    
    int& ret = cache[start][end];
    if (ret != -1) return ret;
    
    ret = INT_MAX;
    
    for (int i = start; i < end; i++) {
        ret = min(ret, solve(start, i) + solve(i+1, end) + arr[start].first*arr[i].second*arr[end].second);
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;
        arr[i] = {r, c};
    }
    
    memset(cache, -1, sizeof(cache));
    cout << solve(0, N-1);
    return 0;
}