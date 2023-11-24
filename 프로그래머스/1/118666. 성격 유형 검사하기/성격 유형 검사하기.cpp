#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    
    int n = survey.size();
    map<char, int> mp;
    
    for (int i = 0; i < n; i++) {
        string s = survey[i];
        int ch = choices[i];
        
        if (ch == 4) continue;
        if (ch > 4) {
            mp[s[1]] += (ch - 4);
        } else if (ch < 4) {
            mp[s[0]] += (4 - ch);
        }
    }
    
    string answer = "";
    
    answer += mp['R'] < mp['T'] ? 'T' : 'R';
    answer += mp['C'] < mp['F'] ? 'F' : 'C';
    answer += mp['J'] < mp['M'] ? 'M' : 'J';
    answer += mp['A'] < mp['N'] ? 'N' : 'A';
    
    return answer;
}