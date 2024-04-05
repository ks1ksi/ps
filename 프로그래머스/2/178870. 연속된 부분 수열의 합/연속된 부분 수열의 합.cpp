#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> seq, int k) {
    vector<int> answer(2);
    int n = seq.size();
    
    int l = 0, r = 0;
    int sum = seq[0];
    int sz = 1e9;
    
    while (l <= r && r < n) {
        if (sum == k) {
            if (sz > r - l + 1) {
                sz = r - l + 1;
                answer[0] = l;
                answer[1] = r;
            }
            r++;
            sum += seq[r];
        }
        else if (sum > k || r == n-1) {
            sum -= seq[l];
            l++;
        }
        else {
            r++;
            sum += seq[r];
        }
    }
    
    return answer;
}