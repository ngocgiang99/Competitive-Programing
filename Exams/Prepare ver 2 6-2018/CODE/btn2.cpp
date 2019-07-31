#include <bits/stdc++.h>
#define FORE(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define X first
#define Y second
#define ll long long
#define mp make_pair
#define pb push_back
#define endl '\n'

const int MAXN = 1e5 * 5;
const int inf = 1e9 + 7;
const int N = 5000;

using namespace std;
int n,ans,f[668][668];
char a[N];

int calc(int i,int c,int mb)
{
    if (f[i][c] != -1) return f[i][c];
    if (i > n)
        if(c == 0) return mb;
        else return 0;
    int kq = 0;
    if (a[i] != ')') kq = max(kq , calc(i+1,c+1,max(mb,c+1)));
    if (a[i] != '(' && c) kq = max(kq , calc(i+1,c-1,mb));
    f[i][c] = kq;
    return kq;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("btn1.inp", "r", stdin);
    freopen("btn1.out", "w", stdout);
    #endif //GIANGPRO
    cin>>a+1; n = strlen(a+1);
    FORE(i,1,n+1)
    FORE(j,0,n) f[i][j] = -1;
    ans = calc(1,0,0);

    return 0;
}
