#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if (n > s) return {-1};
    int x = s / n;
    int m = s % n;
    vector<int> answer;
    for (int i = 0; i < n; i++) {
        if (i >= (n - m)) answer.emplace_back(x + 1);
        else answer.emplace_back(x);
    }
    return answer;
}