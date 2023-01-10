#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> v(n);
    vector<vector<int>> adj(26);
    bool cnt[26] = {0};
    int sz = 0;
    int indegree[26] = {0};

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (char c : v[i]) {
            if (!cnt[c-'a']) {
                sz++;
                cnt[c-'a'] = true;
            }
        }
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < 10; j++) {
            if (v[i].size() == j || v[i+1].size() == j) {
                if (v[i+1].size() == j && v[i].size() > j) {
                    cout << '!';
                    return 0;
                }
                break;
            }
            if (v[i][j] != v[i+1][j]) {
                adj[v[i][j]-'a'].push_back(v[i+1][j]-'a');
                indegree[v[i+1][j]-'a']++;
                break;
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] && !indegree[i]) q.push(i);
    }

    vector<char> ans;
    bool sw = false;

    while (!q.empty()) {
        if (q.size() > 1) sw = true;
        int cur = q.front();
        q.pop();
        ans.push_back(cur+'a');
        for (int next : adj[cur]) {
            if (cnt[next] && !(--indegree[next])) q.push(next);
        }
    }

    if (ans.size() != sz) cout << '!';
    else if (sw) cout << '?';
    else {
        for (char c : ans) {
            cout << c;
        }
    }

    // for (int i = 0; i < 26; i++) {
    //     cout << (char)(i+'a') <<' ';
    //     for (int x : adj[i]) {
    //         cout << (char)(x+'a') << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}