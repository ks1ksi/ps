#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>>& adj, vector<int>& visited, int idx) {
    visited[idx] = 1;
    int ret = 1;
    for (auto x : adj[idx]) {
        if (visited[x]) continue;
        ret += dfs(adj, visited, x);
    }
    return ret;
}


int solution(int n, vector<vector<int>> wires) {
    int answer = 1e9;
    int e = wires.size();
    for (int i = 0; i < e; i++) { // exclude ith edge
        vector<vector<int>> adj(n + 1);
        for (int j = 0; j < e; j++) {
            if (j == i) continue;
            adj[wires[j][0]].emplace_back(wires[j][1]);
            adj[wires[j][1]].emplace_back(wires[j][0]);
        }
        
        int first = 0, second = 0;
        vector<int> visited(n + 1);
        for (int k = 1; k <= n; k++) {
            if (visited[k]) continue;
            int x = dfs(adj, visited, k);
            cout << "k: " << k << " x: " << x << '\n';
            if (first == 0) first = x;
            else second = x;
        }

        
        for (auto x : visited) {
            cout << x << ' ';
        }
        cout << '\n';
        
        cout << "FIRST " << first << " SECOND " << second << '\n';
        
        answer = min(answer, abs(first - second));
    }
    return answer;
}