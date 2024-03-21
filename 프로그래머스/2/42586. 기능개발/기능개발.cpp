#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> pg, vector<int> sp) {
    
    int n = sp.size();
    vector<int> rem(n);
    
    for(int i = 0; i < n; i++) {
        rem[i] = ceil(1.0 * (100 - pg[i]) / sp[i]);
        cout << rem[i] << ' ';
    }
    
    vector<int> answer;
    int cnt = 1, cur = rem[0];
    for (int i = 1; i < n; i++) {
        if (rem[i] > cur) {
            answer.emplace_back(cnt);
            cur = rem[i];
            cnt = 1;
        }
        else cnt++;
    }
    answer.emplace_back(cnt);
    
    return answer;
}