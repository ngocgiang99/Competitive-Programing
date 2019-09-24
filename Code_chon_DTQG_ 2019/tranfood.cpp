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
int w[MAXN], nChild[MAXN];
long long ansmx, ansmi;
long long ans[MAXN];
vector<pair<int,int> > a[MAXN];

void init() {
    cin>> n;
    FOR(i,1,n) {
        int u, v, d;
        cin>> u >> v >> d;

        a[u].pb(mp(v, d));
        a[v].pb(mp(u, d));
    }

    FORE(i,1,n) cin>> w[i];
}

void prepare(int u, int p, int dis) {
    ans[1] += 1ll*w[u]*dis;
    nChild[u] = w[u];
    //cout<< u <<' '<< w[u] <<' '<< dis <<endl;

    FOR(i,0,a[u].size()) {
        int v = a[u][i].fi;

        if (v != p) {
            prepare(v,  u, dis + a[u][i].se);
            nChild[u] += nChild[v];
        }
    }
}

void dfs(int u, int p) {
    //cout<< u <<' '<< ans[u] <<endl;
    FOR(i,0, a[u].size()) {
        int v = a[u][i].fi;

        if (v != p) {
            int nchild = nChild[v];

            //cout<< u <<' '<< v <<' '<< nchild <<' '<< a[u][i].se <<endl;
            ans[v] = ans[u] + 1ll*(nChild[1] - 2*nchild) * a[u][i].se;
            dfs(v, u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("tranfood.inp", "r", stdin);
    freopen("tranfood.out", "w", stdout);
    #endif
    init();
    prepare(1, -1, 0);
    dfs(1, -1);

    ansmx = 0;
    ansmi = 1e16;

    FORE(i,1,n) {
        ansmx = max(ansmx, ans[i]);
        ansmi = min(ansmi, ans[i]);
    }

    cout<< ansmi <<' '<< ansmx <<endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
