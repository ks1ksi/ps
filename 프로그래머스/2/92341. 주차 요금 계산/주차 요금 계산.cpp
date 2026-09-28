#include <bits/stdc++.h>

using namespace std;

// 기본시간 기본요금 단위시간 단위요금
// 0       1     2       3 
int calcFee(int diff, vector<int>& fees) {
    int fee = fees[1];
    if (diff > fees[0]) {
        fee += ceil(double(diff - fees[0]) / fees[2]) * fees[3];
    }
    return fee;
}

// 분, 번호, 입차여부
tuple<int, string, bool> parse(string& record) {
    stringstream ss(record);
    string time, numString, inputString;
    ss >> time >> numString >> inputString;
    
    int minute = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
    bool in = inputString == "IN";
    
    cout << minute << ' ' << numString << ' ' << in << '\n';
    
    return {minute, numString, in};    
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, int> status;
    map<string, int> total;
    
    for (auto& s : records) {
        auto[m, num, in] = parse(s);
        if (in) {
            status[num] = m; // m분 입차
        } else {
            int inputMinute = status[num];
            int diff = m - inputMinute;
            total[num] += diff;
            status[num] = -1;
        }
    }
    
    int lastTime = 24 * 60 - 1;
    
    for (auto[num, inputMinute] : status) {
        if (inputMinute == -1) continue;
        total[num] += lastTime - inputMinute;
    }
    
    for (auto[num, minute] : total) {
        answer.emplace_back(calcFee(minute, fees));
    }
   
    return answer;
}