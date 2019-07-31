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
const int base = 1e2;
const int N = 500;

int n;
int a[N], s[N], dp[N][N];

int sum(int l, int r) {
    return (s[r] - s[l-1]) % base;
}

int calc(int l, int r) {
    if (l == r) return 0;
    if (dp[l][r] != -1) return dp[l][r];

    int res = 1e9;
    FORE(mid,l,r-1)
    res = min(res, calc(l,mid) + calc(mid+1,r) + sum(l,mid)*sum(mid+1,r));

    //cout<< l <<' '<< r << ' '<< res <<' '<< sum(1,1) * sum(2,2) <<endl;
    return dp[l][r] = res;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("mixtures.inp", "r", stdin);
    //freopen("new.out", "w", stdout);
    #endif
    while(cin>> n) {
        FORE(i,1,n) cin>> a[i];
        FORE(i,1,n) s[i] = s[i-1] + a[i];

        memset(dp, -1, sizeof dp);
        cout<< calc(1,n) <<endl;
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
