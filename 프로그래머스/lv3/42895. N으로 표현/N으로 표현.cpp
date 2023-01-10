#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    
    vector<int> v{N};
    for (int i = 1; i < 8; i++) {
        v.push_back(v[i-1]*10+N);
    }
    
    set<int> cache[9];
    for (int i = 0; i < 8; i++) {
        cache[i+1].insert(v[i]);
    }
    
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (i+j > 8) continue;
            for (int a : cache[i]) {
                for (int b : cache[j]) {
                    cache[i+j].insert(a+b);
                    cache[i+j].insert(a-b);
                    cache[i+j].insert(b-a);
                    cache[i+j].insert(a*b);
                    if (b) cache[i+j].insert(a/b);
                    if (a) cache[i+j].insert(b/a);
                }
            }
        }
    }
    
    for (int i = 0; i < 9; i++) {
        if (cache[i].find(number) != cache[i].end()) {
            answer = i;
            break;
        }
    }
    
    return answer;
}