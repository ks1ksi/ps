#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool is_connectable(string& a, string& b) {
    int cnt = 0;
    int sz = a.size();
    
    for (int i = 0; i < sz; i++) {
        if (a[i] == b[i]) cnt++;
    }
    
    return cnt == (sz - 1);
}

int bfs(vector<vector<int>>& adj, int start, int tg) {
    queue<int> q;
    q.emplace(start);
    int dist[51] = {0};
    dist[start] = 1;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int next : adj[cur]) {
            if (!dist[next]) {
                q.emplace(next);
                dist[next] = dist[cur] + 1;
            }
        }
    }
    
    for (int i = 0; i < 10; i++) {
        cout << dist[i] << ' ';
    }
    
    return dist[tg] - 1;
    
}

int solution(string begin, string target, vector<string> words) {
    
    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }
    
    int tg = find(words.begin(), words.end(), target) - words.begin();
    
    cout << "Target: " << tg << '\n';
    
    words.emplace_back(begin);
    int n = words.size();
    vector<vector<int>> adj(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (is_connectable(words[i], words[j])) {
                cout << words[i] << ' ' << words[j] << '\n';
                adj[i].emplace_back(j);
                adj[j].emplace_back(i);
            }
        }
    }
    
    int ans = bfs(adj, n-1, tg);
    return ans == -1 ? 0 : ans;
}