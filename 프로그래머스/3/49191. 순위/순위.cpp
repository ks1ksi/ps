#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> win(n+1, vector<int>(n+1));
    for (auto& v : results) {
        win[v[0]][v[1]] = 1;
    }
    for (int k = 1; k < n + 1; k++) {
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (win[i][k] && win[k][j]) win[i][j] = 1;
            }
        }
    }
    
    for (auto& v : win) {
        for (auto x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    
    
    vector<int> cnt(n + 1);
    
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (win[i][j]) {
                cnt[i]++;
                cnt[j]++;   
            }
        }
    }
    
    cout << '\n';
    for (auto x : cnt) {
        cout << x << ' ';
    }
    cout << '\n';
    
    answer = ranges::count(cnt, n - 1);
    
    return answer;
}