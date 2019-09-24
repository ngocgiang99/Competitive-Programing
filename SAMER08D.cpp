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
const int N = 1005;

int k, m, n;
char a[N], b[N];
int g[N][N], dp[N][N];


void init() {
    cin>> a+1; m = strlen(a+1);
    cin>> b+1; n = strlen(b+1);
}

void prepare() {
    FORE(i,1,m)
    FORE(j,1,n)
    if (a[i] == b[j]) g[i][j] = g[i-1][j-1] + 1;
    else g[i][j] = 0;
}

void process() {
    memset(dp, 0, sizeof dp);
    memset(g, 0, sizeof g);
    prepare();

    FORE(i,1,m)
    FORE(j,1,n) {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        FORE(t,k,g[i][j])
        dp[i][j] = max(dp[i][j], dp[i - t][j - t] + t);
    }

    cout<< dp[m][n] <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("SAMER08D.inp", "r", stdin);
    //freopen("new.out", "w", stdout);
    #endif
    while(cin>> k) {
        //cout<< k <<' '<< 'A' <<endl;
        if (k == 0) break;
        init();
        process();
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
