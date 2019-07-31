#include <bits/stdc++.h>
using namespace std;
#define FORE(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)

#define fi first
#define se second
#define ll long long
#define mp make_pair
#define pb push_back
#define all(a) a.begin(),a.end()
#define sqr(x) (x)*(x)

template <typename G> inline void read(G &x)
{
    x = 0; char c; int dau = 1;
    while(!isdigit(c = getchar())) {if (c == '-') dau = -1;};
    do{x = x*10 + c - '0';} while(isdigit(c = getchar()));
    x = dau*x;
}

template <typename G> inline void write(G x)
{
    if (x > 9) write(x/10);
    putchar(x%10 + '0');
}

template <class T> inline T min(T a,T b,T c){ return min(a,min(b,c)); }
template <class T> inline T min(T a,T b,T c,T d) { return min(a,min(b,c,d)); }
template <class T> inline T max(T a,T b,T c){ return max(a,max(b,c)); }
template <class T> inline T max(T a,T b,T c,T d) { return max(a,max(b,c,d)); }



const int MAXN = 1e5 + 50;
const int base = 1e9 + 7;
const int N = 5000;

int n, m;
long long s[2][MAXN], ans[MAXN];
pair<int,int> a[MAXN], p[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> n >> m;
    FORE(i,1,n) cin>> a[i].fi;
    FORE(i,1,n) cin>> a[i].se;
    FORE(i,1,m) cin>> p[i].fi, p[i].se = i;

    sort(a+1, a+n+1);
    sort(p+1, p+m+1);

    FORE(i,1,n) {
        s[0][i] = s[0][i-1] + a[i].se;
        s[1][i] = s[1][i-1] + 1ll*a[i].fi * a[i].se;
    }
    int j = 1;
    a[n+1].fi = base;
    FORE(i,1,m) {
        while(a[j].fi < p[i].fi) ++j;
        
        ans[p[i].se] = 1ll*p[i].fi*s[0][j-1] - s[1][j-1] + s[1][n] - s[1][j-1] - 1ll*p[i].fi*(s[0][n] - s[0][j-1]);
        
    }
    FORE(i,1,m)
    cout<< ans[i] <<endl;
    return 0;
}