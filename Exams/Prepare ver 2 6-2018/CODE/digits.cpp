#include<bits/stdc++.h>
using namespace std;
#define FORE(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define ll long long
#define endl "\n"

const int MAXN = 1e5 * 5;
const int base  = 1e9 + 7;
const int N = 5000;
const double pi = acos(-1.0);
const double ep = 1e-6;

int n, m;
long long f[19][18*18 + 3][100];

void input() {
    cin>> n >> m;
}

void prepare() {
    FORE(i,0,n)
    FORE(j,0,18*n+1)
    FORE(r,0,99) f[i][j][r] = -1;
}

int sumDigits(int x) {
    int res = 0;
    while(x) {
        res += x%10;
        x /= 10;
    }
    return res;
}

long long calc(int i, int s, int q) {
    if (f[i][s + 9*n][q] != -1) return f[i][s + 9*n][q];
    if (i == n) return (s - sumDigits(q) == 0);
    long long res = 0;
    FORE(t, 0 , 9)
    {
        int qNew = t*m + q;
        res += calc(i+1, s + t - qNew%10, qNew/10);
    }
    return f[i][s + 9*n][q] = res;
}

void process() {
    cout<< calc(0, 0, 0) <<endl;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("digits.inp", "r", stdin);
    freopen("digits.out", "w", stdout);
    #endif
    
    int t;
    cin>> t;
    while(t--) {
        input();
        prepare();
        process();
    }

    return 0;
}
