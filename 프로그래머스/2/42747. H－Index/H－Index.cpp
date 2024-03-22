#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> v) {
    sort(v.begin(), v.end(), [](int a, int b){return a > b;});
    
    int cnt = 0;
    for (auto x : v) {
        if (cnt >= x) break;
        cnt++;
    }
    
    return cnt;
}