#include <string>
#include <vector>

using namespace std;

string solution(string num, int k) {
    int sz = num.size();
    vector<char> v = {num[0]};
    
    for (int i = 1; i < sz; i++) {
        while (k && v.size() && v[v.size()-1] < num[i]) {
            k--;
            v.pop_back();
        }
        v.emplace_back(num[i]);
    }
    
    while (k) {
        v.pop_back();
        k--;
    }
    
    string ans = "";
    for (auto c : v) {
        ans += c;
    }
    return ans;
}