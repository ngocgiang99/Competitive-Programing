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
const int base = 1e6;
const int N = 1005;


int m, n;
int a[N], f[N][N], t[N];
vector<int> adj[N], ve;

void prepare() {
    read(n); read(m);
    FORE(i,1,n) {
        read(a[i]);
        ve.pb(a[i]);
    }

    sort(all(ve));

    FORE(i,1,n) a[i] = lower_bound(all(ve), a[i]) - ve.begin() + 1;
    FORE(i,1,m) {
        int x;
        read(x);
        int j = lower_bound(all(ve), x) - ve.begin();

        if (j == n) continue;
        if (ve[j] != x) continue;

        adj[j+1].pb(i);
    }
}

int Find(int i, int x) {
    int len = adj[a[i]].size();
    int j = upper_bound(adj[a[i]].begin(), adj[a[i]].end(), x) - adj[a[i]].begin();

    if (adj[a[i]].begin() + j == adj[a[i]].end()) return -1;
    //cout<< i <<' '<< a[i] <<' '<< x <<' '<< j <<' '<< adj[a[i]][j]<<endl;
    return adj[a[i]][j];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("lcsmx.inp", "r", stdin);
    freopen("lcsmx.out", "w", stdout);
    #endif
    prepare();



    FORE(i,0,n)
    FORE(j,i+1,n) f[i][j] = base;
    FORE(i,1,n)
    FORE(k,1,i) {
        f[i][k] = f[i-1][k];

        int j = Find(i, f[i-1][k-1]);
        if (j == -1) continue;

        f[i][k] = min(f[i][k], j);

        //cout<< i <<' '<< k <<' '<< j <<' '<< f[i][k] <<" ANS"<<endl;
    }

    int ans = 0;
    int u, v;
    FORE(i,1,n)
    FORE(k,1,i)
    if (f[i][k] != base) {
        if (k > ans) {
            ans = k;
            u = i;
            v = k;
        }
    }

    cout<< ans <<endl;

    int cnt = 0;
    while(u) {
        if (f[u][v] == f[u-1][v]) --u;
        else {
            t[++cnt] = a[u];
            --u;
            --v;
        }
    }
    FORD(i,cnt,1)
    cout<< t[i] <<' ';

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
