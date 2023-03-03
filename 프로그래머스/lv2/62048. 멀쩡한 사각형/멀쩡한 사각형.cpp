#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

ll solution(int w, int h) {
    return (ll) w * h - (w + h) + gcd(w, h);
}