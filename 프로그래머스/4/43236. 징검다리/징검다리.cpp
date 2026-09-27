#include <bits/stdc++.h>

using namespace std;
using ll = long long;


bool check(int distance, vector<int>& rocks, int n, int mid) {
    int cur = 0;
    for (auto x : rocks) {
        if (x - cur < mid) {
            n--;
        } else {
            cur = x;
        }
    }
    if (distance - cur < mid) n--;
    
    return n >= 0;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    
    ll lo = 0, hi = distance;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2; // 최솟값 mid 로 가능한지 확인
        if (check(distance, rocks, n, mid)) {
            answer = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    
    
    return answer;
}