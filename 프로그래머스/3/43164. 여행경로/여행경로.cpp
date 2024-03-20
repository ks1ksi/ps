#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

vector<int> tmp, ans;
int edges[10001][10001];
int n, sz;

void dfs(vector<set<int>>& adj, int cur, int cnt) {
    if (cnt == n && ans.size() == 0) {
        // 티켓 전부 소진
        ans = tmp;
        return;
    }
    
    for (auto iter = adj[cur].begin(); iter != adj[cur].end(); iter++) {
        int next = *iter;
        if (!edges[cur][next]) continue;
        
        edges[cur][next]--;
        tmp.emplace_back(next);
        
        dfs(adj, next, cnt+1);
        
        edges[cur][next]++;
        tmp.pop_back();
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    n = tickets.size();
    
    set<string> st;
    for (auto& v : tickets) {
        for (auto& s : v) {
            st.emplace(s);
        }
    }
    
    vector<string> ct(st.begin(), st.end());
    sz = ct.size();
    
    for (auto x : ct) {
        cout << x << ' ';
    }
    
    map<string, int> mp;
    for (int i = 0; i < sz; i++) {
        mp[ct[i]] = i;
    }
    
    vector<set<int>> adj(sz);
    for (auto& v : tickets) {
        string from = v[0];
        string to = v[1];
        int f = mp[from];
        int t = mp[to];
        adj[f].emplace(t);
        edges[f][t]++;
    }
    
    dfs(adj, mp["ICN"], 0);
    
    vector<string> answer = {"ICN"};
    for (auto x : ans) {
        answer.emplace_back(ct[x]);
    }
    
    return answer;
}