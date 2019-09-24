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



const int MAXN = 1e6 + 5;
const int base = 1e9 + 7;
const int N = 5000;

int n;
int a[MAXN];
long long f[MAXN], g[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    FORE(i,1,n) cin>> a[i];
    long long ans = -1e18;
    long long res = 0;
    long long s = -1e18;

    f[0] = -1e18;
    FORE(i,1,n) {
        s = max(1ll * a[i], s + a[i]);
        //cout<< i <<' '<< s <<endl;
        f[i] = max(f[i-1], s);
    }

    //s = 0;
    g[n+1] = -1e18;
    s = -1e18;
    FORD(i,n,1) {
        s = max(1ll * a[i], s + a[i]);
        //cout<< i <<' '<< s <<endl;
        g[i] = max(g[i+1], s);
    }

    FOR(i,1,n)
    ans = max(ans, f[i] + g[i+1]);

    cout<< ans <<endl;
    return 0;
}
