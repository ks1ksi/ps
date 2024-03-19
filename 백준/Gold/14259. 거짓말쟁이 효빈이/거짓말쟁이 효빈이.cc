#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int n, k, a, m;

// x칸에 전함 몇개 들어가는지
int get_count(int x) {
    if (x == a) return 1;
    if (x < a) return 0;
    return (x - a) / (a + 1) + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> a >> m;

    vector<int> ms(m);
    for (auto& x : ms) cin >> x;
    int cnt = get_count(n);
    set<int> st;
    st.emplace(0);
    st.emplace(n + 1);

    // 미사일 하나씩 받으면서 공간 분리
    for (int i = 0; i < ms.size(); i++) {
        int x = ms[i];
        auto lb = st.lower_bound(x);
        int right = *lb;
        int left = *(prev(lb));

        int before = get_count(right - left - 1);
        int after = get_count(x - left - 1) + get_count(right - x - 1);
        cnt -= (before - after);

        if (cnt < k) {
            cout << i + 1 << '\n';
            return 0;
        }

        st.emplace(x);
    }

    cout << -1 << '\n';

    return 0;
}
