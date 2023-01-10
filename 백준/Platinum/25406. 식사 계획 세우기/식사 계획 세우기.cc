#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    
    vector<priority_queue<int, vector<int>, greater<int>>> vpq(n+1); // vpq[num]: idx pq
    set<pair<int, int>> cset; // count, num
    set<pair<int, int>> iset; // idx, num

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        vpq[v[i]].push(i+1);
        iset.insert({i+1, v[i]});
        if (vpq[v[i]].size() > ceil(n/2.0)) {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vpq[i].empty()) {
            cset.insert({vpq[i].size(), i});
        }
    }

    int last = -1;
    int curn = n;
    while (curn--) {

        auto maxelem = cset.rbegin();

        if ((*maxelem).first > ceil(curn/2.0)) {
            // use maxelem
            auto [cnt, num] = *maxelem;
            int idx = vpq[num].top();

            last = num;
            cout << vpq[num].top() << ' ';

            vpq[num].pop();
            iset.erase({idx, num});
            cset.erase({cnt, num});
            if (cnt-1) cset.insert({cnt-1, num});
        }

        else {
            // use minidx
            auto minidxelem = iset.begin();
            while ((*minidxelem).second == last && minidxelem != iset.end()) minidxelem++;

            auto [idx, num] = *minidxelem;
            int cnt = vpq[num].size();
    
            last = num;
            cout << idx << ' ';

            vpq[num].pop();
            iset.erase({idx, num});
            cset.erase({cnt, num});
            if (cnt-1) cset.insert({cnt-1, num});
        }
    }

    return 0;
}