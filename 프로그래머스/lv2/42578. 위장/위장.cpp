#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, vector<string>> mp;
    
    for (auto& v : clothes) {
        string name = v[0];
        string kind = v[1];
        mp[v[1]].emplace_back(name);
    }
    
    for (auto& [kind, vec] : mp) {
        answer *= vec.size()+1;
    }
    answer--;
    return answer;
}