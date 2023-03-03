#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lt, vector<int> w) {
    vector<int> ans;
    
    int zcnt = 0, cnt = 0;
    for (auto x : lt) {
        if (x == 0) {
            zcnt++;
            continue;
        }
        if (find(w.begin(), w.end(), x) != w.end()) cnt++;
    }
    
    int m = cnt == 0 ? 6 : 7 - cnt;
    int M = cnt + zcnt == 0 ? 6 : 7 - (cnt + zcnt);
    
    ans.emplace_back(M);
    ans.emplace_back(m);
    
    return ans;
}