#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> pv, int limit) {
    sort(pv.begin(), pv.end());
    int l = 0, r = (int)pv.size()-1, ans = 0;
    
    while (l <= r) {
        if (l < r && pv[l] + pv[r] <= limit) {
            ans++;
            l++;
            r--;
        }
        else {
            ans++;
            r--;
        }
    }
    
    return ans;
}