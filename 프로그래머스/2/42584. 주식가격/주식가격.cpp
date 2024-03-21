#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> pv) {
    int n = pv.size();
    vector<int> answer(n);
    
    stack<pair<int, int>> st;
    
    for(int i = 0; i < n; i++) {
        int next = pv[i];
        
        while (st.size() && st.top().first > next) {
            auto [x, idx] = st.top();
            st.pop();
            answer[idx] = i - idx;
        }
        
        st.emplace(pv[i], i);
    }
    
    while(st.size()) {
        auto [x, idx] = st.top();
        st.pop();
        answer[idx] = n - 1 - idx;
    }
    
    
    return answer;
}