#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> er, vector<string> rf, vector<string> seller, vector<int> amount) {
    vector<int> ans;
    
    unordered_map<string, string> p;
    for (int i = 0; i < er.size(); i++) {
        p[er[i]] = rf[i];
    }
    
    unordered_map<string, int> cal;
    for (int i = 0; i < seller.size(); i++) {
        string s = seller[i];
        int cnt = amount[i];
        
        cal[s] += cnt*90;
        int rem = cnt*10;
        s = p[s];
        while (s != "-") {
            cal[s] += rem - (rem / 10);
            rem = rem / 10;
            s = p[s];
            if (rem == 0) break;
        }
    }
    
    for (auto& s : er) {
        ans.emplace_back(cal[s]);
    }
    
    return ans;
}