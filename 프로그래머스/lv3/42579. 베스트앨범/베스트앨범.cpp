#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, int>& p1, const pair<string, int>& p2) {
    return p1.second > p2.second;
}

bool cmp2(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first > p2.first;
}

vector<int> solution(vector<string> gr, vector<int> pl) {
    int sz = gr.size();
    map<string, int> im; // gen, total play
    map<string,  vector<pair<int, int>>> vm; // gen, play, idx
    
    for (int i = 0; i < sz; i++) {
        im[gr[i]] += pl[i];
        vm[gr[i]].emplace_back(pl[i], i);
    }
    
    vector<pair<string, int>> pv; // gen, total play
    for (auto& p : im) {
        pv.emplace_back(p);
    }
    sort(pv.begin(), pv.end(), cmp);
    
    vector<int> ans;
    for (auto& [gen, play] : pv) {
        auto& vec = vm[gen];
        sort(vec.begin(), vec.end(), cmp2);
        ans.emplace_back(vec[0].second);
        if (vec.size() > 1) ans.emplace_back(vec[1].second);
    }
    
    return ans;
}