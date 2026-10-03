#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<tuple<int, int, string>> arr; // start playtime name
    
    int n = plans.size();
    
    for (auto& v : plans) {
        string name = v[0];
        string startString = v[1];
        string playtimeString = v[2];
        
        int start = stoi(startString.substr(0, 2)) * 60 
            + stoi(startString.substr(3, 2));
        int playtime = stoi(playtimeString);
        
        arr.emplace_back(start, playtime, name);
    }
    
    sort(arr.begin(), arr.end());
    
    for (auto&[a, b, c] : arr) {
        cout << a << ' ' << b << ' ' << c << '\n';
    }
    
    int time = 0;
    int end = 0;
    string cur;
    stack<pair<string, int>> st; // name, remain
    
    for (int i = 0; i < n; i++) {
        auto& [t, p, c] = arr[i];
        if (i != 0) {
            if (end > t) {
                st.emplace(cur, end - t);
            }
            else {
                answer.emplace_back(cur);
            }
        } 
        time = t;
        end = t + p;
        cur = c;
        while (1) {
            if (st.empty()) break;
            auto [name, remain] = st.top();
            if (i + 1 < n && get<0>(arr[i + 1]) <= end) break; // 다음시작
            st.pop();
            answer.emplace_back(cur);
            cur = name;
            time = end;
            end = end + remain;
        }
    }
    
    answer.emplace_back(cur);
    
    
    return answer;
}