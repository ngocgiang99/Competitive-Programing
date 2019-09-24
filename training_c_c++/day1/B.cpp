#include <iostream>

using namespace std;

int n, q;
int a[1000005];
long long s[1000005];

int main() {
    cin>> n;
    for (int i = 0; i < n; ++i) cin>> a[i];
    for (int i = 1; i <= n; ++i) s[i] = s[i-1] + a[i-1];

    cin>> q;
    long long ans;
    int res = -1;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin>> l >> r;
        //cout<< i <<' '<< s[r] - s[l-1] <<endl;
        if (res == -1) ans = s[r] - s[l-1], res = i+1;
        else
        if (s[r] - s[l-1] >= ans) {
            ans = s[r] - s[l-1];
            res = i+1;
        }
    }

    cout<< res ;
    return 0;
}