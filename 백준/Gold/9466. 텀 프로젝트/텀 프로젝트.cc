#include <bits/stdc++.h>

using namespace std;

// 0: not visited
// 1: checking
// 2: in team
// 3: no team

int solve(vector<int> &v) {
    int visited[v.size()] = {};
    vector<int> select;
    
    for (int i = 1; i < v.size(); i++) {
        if (visited[i] > 0) continue;
        select.push_back(i);
        int next = i;
        while (visited[next] == 0) {
            visited[next] = 1;
            next = v[next];
            select.push_back(next);
        }
        select.pop_back();
        
        if (visited[next] == 1) { // team
            auto iter = select.begin();
            while (*iter != next) {
                visited[*iter] = 3;
                iter++;
            }
            while (iter != select.end()) {
                visited[*iter] = 2;
                iter++;
            }
        }
        else { // no team
            for (int x : select) {
                visited[x] = 3;
            }
        }
        select.clear();
    }
    
    int cnt = 0;
    for (int x : visited) {
        if (x == 3) {
            cnt++;
        }
    }
    
    return cnt;
    // for (int x : visited) {
    //     cout << x << ' ';
    // }
    // cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v;
        v.push_back(0);
        while (n--) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        // for (int x : v) {
        //     cout << x << ' ';
        // }
        // cout << '\n';
        cout << solve(v) << '\n';
    }
    return 0;
}