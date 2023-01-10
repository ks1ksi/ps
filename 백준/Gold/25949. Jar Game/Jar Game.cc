#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

pair<int, int> cache[101][101][101][30];

pair<int, int> solve(int a, int b, int c, int turn) { // 홀수턴 F, 짝수턴 S
    if (!a && !b && !c) return {0, 0};

    pair<int, int>& ret = cache[a][b][c][turn];
    if (ret != make_pair(-1, -1)) return ret;

    vector<pair<int, int>> rets;

    if (a) {
        pair<int, int> tmp = solve(max(0, a-turn), b, c, turn+1);
        turn % 2 ? tmp.first += min(a, turn) : tmp.second += min(a, turn);
        rets.push_back(tmp);
    }
    if (b) {
        pair<int, int> tmp = solve(a, max(0, b-turn), c, turn+1);
        turn % 2 ? tmp.first += min(b, turn) : tmp.second += min(b, turn);
        rets.push_back(tmp);
    }
    if (c) {
        pair<int, int> tmp = solve(a, b, max(0, c-turn), turn+1);
        turn % 2 ? tmp.first += min(c, turn) : tmp.second += min(c, turn);
        rets.push_back(tmp);
    }

    pair<int, int> ans = {0, 0};

    for (auto& p : rets) {
        if (turn%2) {
            if (p.first > ans.first) ans = p;
        }
        else {
            if (p.second > ans.second) ans = p;
        }
    }

    return ret = ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;    
    cin >> a >> b >> c;

    fill(&cache[0][0][0][0], &cache[100][100][100][30], make_pair(-1, -1));

    auto [f, s] = solve(a, b, c, 1);

    // cout << "F: " << f << '\n';
    // cout << "S: " << s << '\n';
    
    if (f > s) cout << "F";
    else if (f < s) cout << "S";
    else cout << "D";

    return 0;
}