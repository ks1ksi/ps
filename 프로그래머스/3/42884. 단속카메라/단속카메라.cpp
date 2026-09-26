#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    int n = routes.size();
    bool check[10001] = {0};
    sort(routes.begin(), routes.end(), [](auto& a, auto& b) { return a[1] < b[1]; } );
    
    for (int i = 0; i < n; i++) {
        if (!check[i]) {
            int cam = routes[i][1];
            for (int j = 0; j < n; j++) {
                if (routes[j][0] <= cam && cam <= routes[j][1]) check[j] = 1;
            }
            answer++;
        }
    }
    
    
    return answer;
}