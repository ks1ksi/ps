#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_len, int weight, vector<int> tw) {
    int cw = 0, t = 0, n = tw.size();
    queue<int> q;
    
    for (int i = 0; i < bridge_len; i++) {
        q.emplace(0);
    }
    
    // 00000000
    int idx = 0;
    while (idx != n) {
        cw -= q.front();
        q.pop();
        t++;
        // 다리에 올라갈 수 있음
        if (cw + tw[idx] <= weight) {
            cw += tw[idx];
            q.emplace(tw[idx]);
            idx++;
        } 
        
        // 다리에 올라갈 수 없음
        else {
            q.emplace(0);
        }
    }
    
    
    return t + bridge_len;
}