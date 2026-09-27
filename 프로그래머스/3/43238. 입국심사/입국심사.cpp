#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solution(int n, vector<int> times) {
    ll answer = 1e18;
    ll lo = 0, hi = 1e18;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll target = 0;
        for (auto x : times) {
            target += mid / x;
        }
        
        if (target < n) lo = mid + 1;
        else {
            hi = mid - 1; 
            answer = mid;
        }
    }
    
    
    return answer;
}