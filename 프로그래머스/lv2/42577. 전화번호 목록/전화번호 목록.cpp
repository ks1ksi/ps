#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_set<string> st;
    
    for (auto& s : phone_book) {
        st.emplace(s);
    }
    
    for (auto& s : phone_book) {
        for (int i = 1; i < s.size(); i++) {
            string tmp = s.substr(0, i);
            if (st.find(tmp) != st.end()) return false;
        }
    }
    
    return answer;
}