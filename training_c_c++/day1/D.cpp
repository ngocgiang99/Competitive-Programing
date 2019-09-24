#include <iostream>
#include <math.h>

using namespace std;

const int MAXN = 2e6 + 10;

int m;
int nPrime[MAXN], s[MAXN];

void prepare() {
    int x = sqrt(MAXN);
    for (int i = 2; i < x; ++i)
    if (!nPrime[i]) {
        //cout<< i <<endl;
        for (int j = i*i; j < MAXN; j += i) nPrime[j] = 1;
    }

    for (int i = 2; i < MAXN; ++i) 
        s[i] = s[i-1] + (nPrime[i] == 0);

}

int main() {
    prepare();

    cin>> m;
    while(m--) {
        int n;
        cin>> n;
        cout<< s[2*n] - s[n-1] <<endl;
    }

}