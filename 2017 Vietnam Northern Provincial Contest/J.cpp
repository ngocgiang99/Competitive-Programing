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

typedef pair<int,int> ii;

struct edges {
    int u, v, w;
    edges() {
        this->u = 0;
        this->v = 0;
        this->w = 0;
    }
    edges(int _u, int _v, int _w) {
        this->u = _u;
        this->v = _v;
        this->w = _w;
    }
};

edges e[N];

int n, m;
int f[N], g[210][210], cx[N];
vector<ii> a[N];

void init() {
    cin>> n >> m;
    FORE(i,1,m) {
        int u, v, w;
        cin>> u >> v >> w;
        e[i] = edges(min(u,v), max(u,v), w);
        a[u].pb(ii(v, w));
        a[v].pb(ii(u, w));
    }

    FORE(i,1,n) a[i].pb(ii(0,0));
}

void dijkstrag(int s) {
    FORE(i,1,n) g[s][i] = base;
    g[s][s] = 0;
    priority_queue<ii> h;

    h.push(ii(0, s));

    while(h.size()) {
        int u = h.top().se;
        int gu = -h.top().fi;
        h.pop();

        if (gu != g[s][u]) continue;

        for(int i = 0; int v = a[u][i].fi; ++i)
        if (g[s][u] + a[u][i].se < g[s][v]) {
            g[s][v] = g[s][u] + a[u][i].se;
            h.push(ii(-g[s][v], v));
        }
    }
}

int check(int u, int v, int i) {
    if (u > v) swap(u, v);
    return (u == e[i].u) & (v == e[i].v);
}

void dijkstraf(int s, int ind) {
    FORE(i,1,n) f[i] = base;
    f[s] = 0;
    priority_queue<ii> h;

    h.push(ii(0, s));

    while(h.size()) {
        int u = h.top().se;
        int fu = -h.top().fi;
        h.pop();

        if (fu != f[u]) continue;

        for(int i = 0; int v = a[u][i].fi; ++i)
        if (check(u, v, ind) == 0 && f[u] + a[u][i].se < f[v]) {
            f[v] = f[u] + a[u][i].se;
            h.push(ii(-f[v], v));
        }
    }
}

void process() {
    double ans = -1.0;
    cout<<fixed<<setprecision(6);

    FORE(i,1,n) dijkstrag(i);

    FORE(i,1,m) {
        FORE(u, 1, n) {
            dijkstraf(u, i);
            FORE(v, 1, n)
            if (f[v] != base && u != v) {

                ans = max(ans, (double) f[v] / g[u][v]);
            }
        }
    }


    cout<< ans <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("new.inp", "r", stdin);
    //freopen("new.out", "w", stdout);
    #endif

    init();
    process();

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
