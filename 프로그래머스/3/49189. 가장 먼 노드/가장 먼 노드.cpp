#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> adj(n + 1);
    for (auto& e : edge) {
        adj[e[0]].emplace_back(e[1]);
        adj[e[1]].emplace_back(e[0]);
    }
    
//     for (int i = 0; i < n + 1; i++) {
//         cout << "i " << i << ": ";
//         for (auto x : adj[i]) {
//             cout << x << " ";
//         }
//         cout << '\n';
//     }
    
    vector<int> visited(n + 1);
    queue<int> q; 
    q.emplace(1);
    visited[1] = 1;
    
    while (q.size()) {
        int cur = q.front(); q.pop();
        for (auto next : adj[cur]) {
            if (visited[next]) continue;
            q.emplace(next);
            visited[next] = visited[cur] + 1;
        }
    }
    
//     for (auto x: visited) {
//         cout << x << ' ';
//     }
//     cout << '\n';
    
    int m = ranges::max(visited);
    int answer = ranges::count(visited, m);
    
    return answer;
}