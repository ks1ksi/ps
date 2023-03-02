#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    set<int> lst(lost.begin(), lost.end()), rst(reserve.begin(), reserve.end());
    for (auto x : lst) {
        if (rst.find(x) != rst.end()) {
            rst.erase(x);
            lst.erase(x);
        }
    }
    
    for (auto x : rst) {
        if (lst.find(x-1) != lst.end()) {
            lst.erase(x-1);
        }
        else if (lst.find(x+1) != lst.end()) {
            lst.erase(x+1);
        }
    }
    
    return n - (int)lst.size();
}