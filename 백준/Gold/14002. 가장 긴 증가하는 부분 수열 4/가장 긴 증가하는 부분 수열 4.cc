#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1000001];
int arr2[1000001]; // 증가 부분 수열에서 이전 값의 인덱스
vector<int> v; // 값
vector<int> v2; // 자기 인덱스

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    v.push_back(-1000000001);
    v2.push_back(-1);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        auto iter = lower_bound(v.begin(), v.end(), arr[i]);
        if (iter == v.end()) {
            v.push_back(arr[i]);
            v2.push_back(i);
            arr2[i] = *(v2.end()-2);
        }
        else {
            *iter = arr[i];
            v2[iter-v.begin()] = i;
            arr2[i] = v2[iter-v.begin()-1];
        }
    }

    cout << v.size()-1 << '\n';

    vector<int> v3;
    int idx = *(v2.end()-1);
    while (idx != -1) {
        v3.push_back(arr[idx]);
        idx = arr2[idx];
    }

    for (auto iter = v3.rbegin(); iter != v3.rend(); iter++) {
        cout << *iter <<' ';
    }

    // for (int x : v) {
    //     cout << x << ' ';
    // }
    // cout << '\n';

    // for (int x : v2) {
    //     cout << x <<' ';
    // }
    // cout << '\n';

    // for (int i = 0; i < N; i++) {
    //     cout << arr2[i] << ' ';
    // }

    return 0;
}