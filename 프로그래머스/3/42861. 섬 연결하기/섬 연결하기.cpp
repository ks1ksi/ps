#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p(101);

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (a == b) return;
    
    p[a] += p[b];
    p[b] = a;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    fill(p.begin(), p.end(), -1);
    
    vector<tuple<int, int, int>> tv;
    for (auto& v : costs) {
        tv.emplace_back(v[2], v[0], v[1]);
    }
    
    sort(tv.begin(), tv.end());
    
    for (auto [c, a, b] : tv) {
        if (find(a) != find(b)) {
            answer += c;
            merge(a, b);
        }
    }
    
    return answer;
}