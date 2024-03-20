#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> pq(works.begin(), works.end());
    
    while (n-- && !pq.empty()) {
        int x = pq.top();
        pq.pop();
        if (x > 1) pq.emplace(--x);
    }
    
    long long answer = 0;
    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        answer += 1L * x * x;
    }
    return answer;
}