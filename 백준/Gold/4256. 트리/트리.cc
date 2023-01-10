#include <bits/stdc++.h>

using namespace std;

vector<int> inorder;
vector<int> preorder;
int N;

void solve(int is, int ie, int ps, int pe){
    if (is > ie) return;
    
    int root = is;
    while (inorder[root] != preorder[ps]) root++;
    
    int lis, lie, lps, lpe; // left
    int ris, rie, rps, rpe; // right
    
    lis = is;
    lie = root - 1;
    ris = root + 1;
    rie = ie;
    
    lps = ps+1;
    lpe = lps + (lie-lis);
    rps = lpe + 1;
    rpe = pe;
    
    solve(lis, lie, lps, lpe);
    solve(ris, rie, rps, rpe);
    cout << preorder[ps] << ' ';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    
    while (t--) {
        int x;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> x;
            preorder.push_back(x);
        }
        for (int i = 0; i < N; i++) {
            cin >> x;
            inorder.push_back(x);
        }
        solve(0, N-1, 0, N-1);
        cout << '\n';
        inorder.clear();
        preorder.clear();
    }
    return 0;
}