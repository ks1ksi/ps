#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(string& a, string& b) {
    string s1 = a + b;
    string s2 = b + a;
    
    return s1 > s2;
}

string solution(vector<int> numbers) {
    vector<string> v;
    for (auto x : numbers) {
        v.emplace_back(to_string(x));
    }
    
    sort(v.begin(), v.end(), cmp);
    
    string answer = "";
    for (auto& s : v) {
        if (answer == "0") continue;
        answer += s;
    }

    return answer;
}