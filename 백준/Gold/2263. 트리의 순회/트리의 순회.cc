#include <bits/stdc++.h>

using namespace std;

vector<int> inorder;
vector<int> postorder;
int N;

void solve(int is, int ie, int ps, int pe){
    if (is > ie) return;
    cout << postorder[pe] << ' ';
    
    int root = is;
    while (inorder[root] != postorder[pe]) root++;
    
    // cout << "\nRoot is " << inorder[root] << '\n';
    
    int lis, lie, lps, lpe; // left
    int ris, rie, rps, rpe; // right
    
    lis = is;
    lie = root - 1;
    ris = root + 1;
    rie = ie;
    
    lps = ps;
    lpe = ps + (lie-lis);
    rps = lpe + 1;
    rpe = pe-1;
    
    // cout << "-------------------" << '\n';
    // for (int i = lis; i <= lie; i++) {
    //     cout << inorder[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = ris; i <= rie; i++) {
    //     cout << inorder[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = lps; i <= lpe; i++) {
    //     cout << postorder[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = rps; i <= rpe; i++) {
    //     cout << postorder[i] << ' ';
    // }
    // cout << '\n';
    // cout << "-------------------" << '\n';    
    
    solve(lis, lie, lps, lpe);
    solve(ris, rie, rps, rpe);
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        inorder.push_back(x);
    }
    for (int i = 0; i < N; i++) {
        cin >> x;
        postorder.push_back(x);
    }
    
    solve(0, N-1, 0, N-1);
    
    return 0;
}

