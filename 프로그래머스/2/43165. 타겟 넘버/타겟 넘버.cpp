#include <string>
#include <vector>

using namespace std;

int dfs(vector<int>& numbers, int cur, int i, int target) {
    if (i == numbers.size()) {
        return cur == target;
    }
    
    return dfs(numbers, cur + numbers[i], i+1, target)
        + dfs(numbers, cur - numbers[i], i+1, target);
}

int solution(vector<int> numbers, int target) {
    int answer = dfs(numbers, 0, 0, target);
    
    return answer;
}