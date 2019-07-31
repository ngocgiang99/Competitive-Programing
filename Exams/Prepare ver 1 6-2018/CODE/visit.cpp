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
const int N = 5000;


int n;
int l[MAXN], r[MAXN];
int f[MAXN][5];

int dis(int u1, int v1, int u2, int v2) {
    return abs(u2 - u1) + abs(v2 - v1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("visit.inp", "r", stdin);
    freopen("visit.out", "w", stdout);
    #endif
    cin>> n;
    FORE(i,1,n) cin>> l[i] >> r[i];
    f[1][0] = r[1] - 1 + r[1] - l[1];
    f[1][1] = l[1] - 1 + r[1] - l[1];
    
    //cout<< 1 <<' '<< f[1][0] <<' '<< f[1][1] <<endl;
    FORE(i,2,n) {
        f[i][1] = min(f[i-1][0] + dis(i-1,l[i-1],i,l[i]), f[i-1][1] + dis(i-1,r[i-1],i,l[i])) + r[i] - l[i] ;
        f[i][0] = min(f[i-1][0] + dis(i-1,l[i-1],i,r[i]), f[i-1][1] + dis(i-1,r[i-1],i,r[i])) + r[i] - l[i] ;
        //cout<< i <<' '<< f[i][0] <<' '<< f[i][1] <<endl;
    }
    int ans = min(f[n][0] + dis(n,l[n],n,n), f[n][1] + dis(n,r[n],n,n));

    cout<< ans <<endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
