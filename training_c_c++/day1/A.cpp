#include <bits/stdc++.h>

using namespace std;

long long a, b, Mod;

long long mul(long long a, long long b) {
    long long res = 0;
    while(b) {
        if (b&1) res = (res + a) % Mod;
        a = (a + a) % Mod;
        b >>= 1;
    }
    return res;
}

long long calc(long long x) {
    if (x == 0) return 0;
    long long a = x;
    long long b = x+1;
    long long c = 2*x+1;
    if (a%2 == 0) a = a/2;
    else if (b%2 == 0) b = b/2;
    else if (c%2 == 0) c = c/2;

    if (a%3 == 0) a = a/3;
    else if (b%3 == 0) b = b/3;
    else if (c%3 == 0) c = c/3;
    
    return mul(a,mul(b,c));
}


int main() {
    cin>> a >> b >> Mod;
    //cout<< mul(5, 6) <<endl;
    //cout<< calc(b) << ' ' << calc(a-1) <<endl;
    cout<< (calc(b) - calc(a-1) + Mod) % Mod;

    return 0;
}