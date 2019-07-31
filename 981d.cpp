#include <bits/stdc++.h>
using namespace std;
#define FORE(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORIT(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define fi first
#define se second
#define ll long long
#define mp make_pair
#define pb push_back
#define all(a) a.begin(),a.end()
#define sqr(x) (x)*(x)
#define endl '\n'

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



const int MAXN = 1e5 * 5;
const int base = 1e9 + 7;
const int N = 60;


int n, k, m;
int c[N];
ll ans;
ll a[N], f[N][N], g[N][N];

int getbit(long long stage, long long i) {
    return (stage>>(i-1)) & 1;
}

int check(long long stage) {
    if (m == 0) return 1;
    FORE(i,1,m)
    if (getbit(stage, c[i]) == 0) return 0;
    return 1;
}

ll Pow(ll x, ll a) {
    ll res = 1;
    FORE(i,1,a) res *= x;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("981d.inp", "r", stdin);
    freopen("981d.out", "w", stdout);
    #endif
    cin>> n >> k;
    FORE(i,1,n) cin>> a[i];

    FORE(i,1,n)
    FORE(j,i,n)
    if (i == j) g[i][j] = a[i];
    else g[i][j] = g[i][j-1] + a[j];

    f[0][0] = 1;
    FORD(bit,60,1)
    {
        FORE(j,1,k)
        FORE(i,1,n) f[i][j] = 0;

        c[++m] = bit;
        FORE(j,1,k)
        FORE(i,j,n)
        FORE(t,j,i)
        if (check(g[t][i])) {
            f[i][j] = f[i][j] | f[t-1][j-1];
        }
        if (f[n][k] == 0) --m;
        else ans += Pow(2,bit-1);

        //cout<< bit <<' '<< m <<endl;
    }

    /*FORE(i,1,n) f[i][1] = g[1][i];
    FORE(j,2,k)
    FORE(i,1,n) f[i][j] = 0;

    FORE(j,1,k)
    FORE(i,j,n)
    FORE(t,j,i)
    if (check(g[t][i])) {
        f[i][j] = max(f[i][j], f[t-1][j-1] & g[t][i]);
    }*/

    cout<< ans <<endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
