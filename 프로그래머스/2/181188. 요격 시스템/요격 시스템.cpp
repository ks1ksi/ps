#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    
    sort(targets.begin(), targets.end());
    int n = targets.size();
    
    int answer = 0;
    int s = targets[0][0], e = targets[0][1];
    for (int i = 1; i < n; i++) {
        int ns = targets[i][0], ne = targets[i][1];
        
        if (ns >= e) {
            answer++;
            s = ns;
            e = ne;
        }
        else if (ne < e) {
            e = ne;
        }
    }
    
    return answer + 1;
}