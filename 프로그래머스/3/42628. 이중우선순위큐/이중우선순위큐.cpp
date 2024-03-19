#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<pair<char, int>> oper;
    set<int> st;
    
    for (auto& s : operations) {
        char c = s[0];
        int num = stoi(s.substr(2));
        oper.emplace_back(c, num);
    }
    
    for (auto& [o, n] : oper) {
        if (o == 'I') st.emplace(n);
        if (o == 'D' && st.size()) {
            if (n == -1) st.erase(st.begin());
            else st.erase(--st.end());
        }
    }
    
    vector<int> ans;
    if (st.empty()) {
        ans = {0, 0};
    }
    else {
        ans = {*st.rbegin(), *st.begin()};
    }

    return ans;
}