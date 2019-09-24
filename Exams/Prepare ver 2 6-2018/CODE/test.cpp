#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 2e6 + 10;

int n, mx;
vector<int> nt[MAXN];
int a[MAXN];
long long ans;
 

void input() {
    cin>> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>> x;
        ++a[x];
        mx = max(mx, x);
    }
    if (n > 1) ans = n;
}

void prepare() {
	for (int i = 2; i <= mx; ++i) {
        long long res = 0;
        int cnt = 0;
        for (int j = i; j <= mx; j += i) {
            //cout<< i <<' '<< j <<' '<< a[j] <<endl;
            res = res + 1ll*a[j]*i;
            cnt += a[j];
        }
        if (cnt > 1)
        ans = max(ans, res);
    }
    cout<< ans <<endl;
}
 
int main() {
    input();
	prepare();
	//cout << 1000 * clock() / CLOCKS_PER_SEC;
	return 0;
}