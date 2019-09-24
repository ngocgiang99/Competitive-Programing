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



const int MAXN = 4100;
const int base = 1e9 + 7;
const int N = 500;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int m, n;
int a[15][2005];
int f[MAXN];
vector<int> adj[MAXN], va[MAXN];
int g[MAXN][2005];

void init() {
    cin>> m >> n;
    FOR(i,0,m)
    FOR(j,0,n) {
        cin>> a[i][j];
    }
}

int getBit(int x, int i) {
    return (x >> (i-1)) & 1;
}

void prepare() {
    int maxMask = (1 << m);
    
    FORE(x,0,maxMask) f[x] = 0;
    FORE(x,0,maxMask) {
        va[x].clear();
        adj[x].clear();
    }

    int cnt = 0;
    FORD(x, maxMask - 1, 0){
        FOR(y, 1, maxMask)
        if ((x&y) == 0) adj[x].pb(y);
        cnt += adj[x].size();
        adj[x].pb(0);
    }

    FOR(x, 0, maxMask)
    FORE(i, 0, m)
    if (getBit(x, i)) va[x].pb(i-1);

    FOR(j, 0, n)
    FOR(x, 0, maxMask) {
        int tmp = 0;
        FOR(i, 0, m) {
            int temp = 0;
            FOR(k, 0, va[x].size())
            temp += a[(i + va[x][k])%m][j];
            tmp = max(tmp , temp);
        }

        g[x][j] = tmp;
    }
}

void process() {
    int ans = 0;
    int maxMask = (1 << m);

    FOR(j, 0, n)
    FORD(x, maxMask - 1, 0)
    for (int k = 0; int y = adj[x][k]; ++k) {

        int tmp = 0;
        int tmpJ = 0;
        int xx = x | y;
        
        // cout<< j <<' '<< x <<' '<< y <<' '<< f[x] <<' '<< g[y][j] <<endl;
        f[xx] = max(f[xx], f[x] + g[y][j]);
    }

    cout<< f[maxMask - 1] <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    // freopen("input.inp", "r", stdin);
    // freopen("output.out", "w", stdout);
    #endif
    int t;
    cin>> t;
    while(t--) {
        init();
        prepare();
        process();
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}