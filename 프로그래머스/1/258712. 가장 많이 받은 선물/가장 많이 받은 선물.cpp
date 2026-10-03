#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    map<string, map<string, int>> give;
    map<string, map<string, int>> take;
    
    for (auto& s : gifts) {
        stringstream ss(s);
        string g, t;
        ss >> g >> t;
        give[g][t]++;
        take[t][g]++;
    }
    
    
    for (auto& [k, v] : give) {
        cout << k << ": ";
        for (auto& [kk, vv] : v) {
            cout << kk << ' ' << vv << ' ';
        }
        cout << '\n';
    }
    
    map<string, int> score;
    
    for (auto& s : friends) {
        int g = 0;
        for (auto& [k, v] : give[s]) {
            g += v;
        }
        
        int t = 0;
        for (auto& [k, v] : take[s]) {
            t += v;
        }
        score[s] = g - t; 
    }
    
    for (auto& [k, v] : score) {
        cout << k << ' ' << v << '\n';
    }
    
    map<string, int> ans;
    
    for (auto& s1 : friends) {
        for (auto& s2 : friends) {
            if (s1 == s2) continue;
            
            if (give[s1][s2] > give[s2][s1]) {
                ans[s1]++;
            }
            else if (give[s1][s2] < give[s2][s1]) {
                ans[s2]++;
            }
            else {
                if (score[s1] > score[s2]) {
                    ans[s1]++;
                }
                else if (score[s1] < score[s2]) {
                    ans[s2]++;
                }
            }
        }
    }
    
    cout << "ANS====\n";
    for (auto& [k, v] : ans) {
        cout << k << ' ' << v << '\n';
    }
    
    for (auto& [k, v] : ans) {
        answer = max(answer, v);
    }
    
    return answer / 2;
}