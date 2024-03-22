#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n = jobs.size();
    
    // 작업 수행하고 있지 않을 때 먼저 들어온거 강제 처리
    // 작업 수행중일 때 다른 작업 들어오면 일단 우선순위 큐에 넣기
    // 그중 가장 먼저 끝나는 친구 집어서 끝내기

    sort(jobs.begin(), jobs.end());
    
    // delay, req
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    int t = 0; // 현재 진행중인 작업이 끝나는 시각
    int i = 0; // 다음 작업 인덱스
    
    while (i < n) {
        // 현재 작업의 종료 전에 요청되는 모든 작업 pq에 넣기
        // t가 변경될 때마다 수행해야 함
        while (i < n && jobs[i][0] <= t) {
            pq.emplace(jobs[i][1], jobs[i][0]);
            i++;
        }
        // pq에 작업 존재하면 그중 가장 일찍 끝나는 작업 수행
        // t 업데이트
        if (pq.size()) {
            auto [d, r] = pq.top();
            pq.pop();
            t += d;
            answer += t - r;            
        }
        // pq에 아무것도 없는 경우 다음 작업 가져와서 해야함
        else {
            int d = jobs[i][1];
            int r = jobs[i][0];
            i++;
            t = r + d;
            answer += t - r;
        }
    }
    
    // 남은 작업 같은 기준으로 처리
    while (pq.size()) {
       auto [d, r] = pq.top();
        pq.pop();
        t += d;
        answer += t - r; 
    }
    
    return answer / n;
}