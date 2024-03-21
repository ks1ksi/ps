#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> p, int location) {
    int n = p.size();
    pair<int, int> target;
    
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    
    for(int i = 0; i < n; i++) {
        q.emplace(p[i], i);
        pq.emplace(p[i]);
        if (i == location) {
            target = {p[i], i};
        }
    }
    
    int cnt = 0;
    while (!q.empty()) {
        auto [x, idx] = q.front();
        if (x == pq.top()) {
            cnt++;
            if (q.front() == target) return cnt;
            q.pop();
            pq.pop();
        }
        else {
            q.emplace(q.front());
            q.pop();
            location++;
            if (location == n) location = 0;
        }
    }
    
    return -1;
}