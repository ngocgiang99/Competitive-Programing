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

int n, q, t;
int sum;
int h[MAXN], d1[MAXN], d2[MAXN], par[MAXN][20];
vector<int> a[MAXN], ca[MAXN], cb[MAXN];

void init() {
    read(n);
    FORE(i,1,n) {
        a[i].clear();
        ca[i].clear();
        cb[i].clear();
    }
    sum = 0;

    FOR(i,1,n) {
        int u, v, c1, c2;
        read(u); read(v); read(c1), read(c2);
        a[u].pb(v); ca[u].pb(c1); cb[u].pb(c2);
        a[v].pb(u); ca[v].pb(c2); cb[v].pb(c1);
        sum = sum + c1 + c2;
    }

}

void dfs(int u, int p) {
    int mxh = log2(h[u]);

    FORE(i,1,mxh) par[u][i] = par[par[u][i-1]][i-1];

    for(int i = 0; int v = a[u][i]; ++i)
    if (v != p) {
        d1[v] = d1[u] + ca[u][i];
        d2[v] = d2[u] + cb[u][i];
        par[v][0] = u;
        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

int LCA(int u, int v) {
    if (h[u] > h[v]) swap(u, v);
    while(h[v] > h[u]) {
        int hdis = log2(h[v] - h[u]);
        v = par[v][hdis];
    }

    if (u == v) return u;

    int hdis = log2(h[v]);
    FORD(i,hdis,0)
    if (par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
    }

    return par[u][0];
}

int dist(int d[], int u, int w) {
    return d[u] - d[w];
}

int get(int u, int v) {
    int w = LCA(u, v);
    //cout<< u <<' '<< v <<' '<< w <<endl;
    //cout<< sum <<' '<< dist(d1, u, w) <<' '<< dist(d2, v, w) <<endl;
    return sum - dist(d1, u, w) - dist(d2, v, w);
}

void prepare() {
    FORE(i,1,n) a[i].pb(0);

    dfs(1, -1);
    //cout<< d2[2] <<endl;
    //cout<< d2[5] <<endl;
}

void process() {
    read(q);
    while(q--)  {
        int u, v;
        read(u); read(v);
        int w = LCA(u, v);

        cout<< get(u, v) <<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    read(t);
    while(t--) {
        init();
        prepare();
        process();
    }



    return 0;
}