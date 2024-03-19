#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> tri) {
    int dp[500][500] = {0};
    dp[0][0] = tri[0][0];
    int sz = tri.size();
    
    for (int i = 1; i < sz; i++) {
        for (int j = 0; j < i + 1; j++) {
            dp[i][j] = max(dp[i][j], dp[i-1][j] + tri[i][j]);
            if (j != 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + tri[i][j]);
        }
    }
    
    return *max_element(begin(dp[sz-1]), end(dp[sz-1]));
}