#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n), cntv(1000001);
    for (auto& x : v) {
        cin >> x;
        cntv[x]++;
    }

    vector<int> ans(n);
    fill(ans.begin(), ans.end(), -1);
    
    stack<pair<int ,int>> st;
    st.push({v[0], 0});
    for (int i = 1; i < n; i++) {
        while (!st.empty()) {
            int cnt = cntv[st.top().first];
            if (cnt < cntv[v[i]]) {
                ans[st.top().second] = v[i];
                st.pop();
            }
            else break;
        }
        st.push({v[i], i});
    }
    
    for (auto x : ans) {
        cout << x << ' ';
    }

    return 0;
}