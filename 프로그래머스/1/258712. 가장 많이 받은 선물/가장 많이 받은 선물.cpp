#include <bits/stdc++.h>

using namespace std;


int solution(vector<string> friends, vector<string> gifts) {
    int n = friends.size();

    unordered_map<string, int> id;
    for (int i = 0; i < n; i++) {
        id[friends[i]] = i;
    }

    vector<vector<int>> give(n, vector<int>(n, 0));
    vector<int> score(n, 0);
    vector<int> received(n, 0);

    for (const auto& gift : gifts) {
        stringstream ss(gift);
        string from, to;
        ss >> from >> to;

        int a = id[from];
        int b = id[to];

        give[a][b]++;
        score[a]++;
        score[b]--;
    }

    for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            int diff = give[a][b] - give[b][a];

            if (diff == 0) {
                diff = score[a] - score[b];
            }

            if (diff > 0) {
                received[a]++;
            } else if (diff < 0) {
                received[b]++;
            }
        }
    }

    return *max_element(received.begin(), received.end());
}