#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9+7;
const ll BASE = 31;
const int MAX = 500005;

ll power[MAX];
ll H;
int N, ANS;
string P;
vector<vector<pair<int, char>>> v;
vector<char> vc;

void dfs(int cur, ll hash) {
    if (hash == H) ANS++;
    for (auto p : v[cur]) {
        int nxt = p.first;
        char c = p.second;
        vc.push_back(c);
        ll h = hash;
        if (vc.size() >= P.size()) {
            h = h - vc[vc.size()-1-P.size()]*power[P.size()-1]%MOD + MOD;
        }
        h = (h*BASE + vc[vc.size()-1])%MOD;
        dfs(nxt, h);
        vc.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    v.resize(N+1);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    cin >> P;

    power[0] = 1;
    for (int i = 1; i <= N; i++) {
        power[i] = power[i-1]*BASE%MOD;
    }
    for (int i = 0; i < P.size(); i++) {
        H = (H*BASE + P[i])%MOD;
    }
    
    dfs(1, 0);
    cout << ANS;

    return 0;
}