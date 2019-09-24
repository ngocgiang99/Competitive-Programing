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
int n,ans,f[668][668], g[668][668][2];
char a[N];
long long cnt = 0;

int calc(int i,int c,int mb)
{
    if (f[i][c] != -1) return f[i][c];
    ++cnt;
    if (i > n) {
        //if (mb == 6) cout<< i <<' '<< c <<' '<< mb <<endl;
        if(c == 0) return mb;
        else return 0;
    }
    int kq = 0;
    if (a[i] != ')') kq = max(kq , calc(i+1,c+1,max(mb,c+1)));
    if (a[i] != '(' && c) kq = max(kq , calc(i+1,c-1,mb));
    f[i][c] = kq;
    //cout<< i <<' '<< c <<' '<< kq <<endl;
    return kq;
}

int trace(int i, int c, int ok) {
    if (g[i][c][ok] != -1) return g[i][c][ok];
    ++cnt;
    if (i > n) {
        if (c == 0 && ok == 1) return g[i][c][ok] = ok;
        return g[i][c][ok] = 0;
    }
    int kq = 0;
    if (a[i] != ')') kq = max(kq, trace(i+1, c+1, ok | (c+1 == ans)));
    if (a[i] != '(' && c) kq = max(kq, trace(i+1, c-1, ok));
    //cout<< i <<' '<< c <<' '<< k <<' '<< kq <<endl;
    return g[i][c][ok] = kq;
}

void truyvet(int i, int c, int ok) {
    //cout<< i <<' '<< c <<' '<< ok <<' '<< trace(i+1, c-1, ok) <<' '<< trace(i+1, c+1, ok | (c+1 >= ans)) <<endl;
    if (i > n) return;
    //++cnt;
    if (a[i] != '(' && c && trace(i+1, c-1, ok) == 1) {
        cout<< ")";
        truyvet(i+1, c-1, ok);
    }
    else {
        cout<< "(";
        truyvet(i+1, c+1, ok | (c+1 == ans));
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("btn2.inp", "r", stdin);
    freopen("btn2.out", "w", stdout);
    #endif //GIANGPRO
    cin>>a+1; n = strlen(a+1);
    FORE(i,1,n+1)
    FORE(j,0,n) f[i][j] = g[i][j][0] = g[i][j][1] = -1;
    ans = calc(1,0,0);
    //cout<< ans <<endl;
    //cout<< cnt <<endl;
    //cout<< n <<endl;
    //int pp = trace(1, 0, 0);
    //cout<< pp <<endl;
    //cnt = 0;
    truyvet(1, 0, 0);
    //cout<< endl << cnt <<endl;
    return 0;
}
