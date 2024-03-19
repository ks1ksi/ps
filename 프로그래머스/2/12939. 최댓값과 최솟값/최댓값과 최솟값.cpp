#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    
    vector<int> sv;
    string buffer = "";
    for (auto& c : s) {
        if (c == ' ') {
            sv.emplace_back(stoi(buffer));
            buffer = "";
        }
        else {
            buffer += c;
        }
    }
    sv.emplace_back(stoi(buffer));
    sort(sv.begin(), sv.end());
    
    return to_string(sv[0]) + " " + to_string(sv[sv.size()-1]);
}