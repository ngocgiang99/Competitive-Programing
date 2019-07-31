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
const int N = 500;

int n;
int ans;
int a[N][N], g[N][N];
int f[N];


void init() {
    cin>> n;
    FORE(i,1,n) {
        int x, r;
        cin>> x >> r;
        a[x+100 - r][x+100 + r]++;
    }

    memset(g, -1, sizeof g);
}

int get(int l, int r) {
    if (l == r) return 0;
    if (g[l][r] != -1) return g[l][r];

    int res = 0;
    FORE(mid,l+1,r-1)
    res = max(res, get(l,mid) + get(mid,r) + a[l][r]);

    return g[l][r] = res;
}

void process() {
    FORE(i,1,300){
        FORE(j,1,i)
        f[i] = max(f[i], f[j-1] + get(j,i));
        ans = max(ans, f[i]);
    }
    
    cout<< n - ans <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("cyrcles.inp", "r", stdin);
    freopen("cyrcles.out", "w", stdout);
    #endif
    init();
    process();

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
