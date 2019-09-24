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



const int MAXN = 1e5 ;
const int base = 1e9 + 7;
const int N = 5000;

struct edge{
    int u, v;
}e[MAXN];

struct queries {
    int l, r, pos;
}query[MAXN];

int n, m, q;
int k, ans, preans, lef;
int color[MAXN], precolor[MAXN], res[MAXN];


void init() {
    cin>> n >> m;
    FORE(i,1,m) {
        int u, v;
        cin>> u >> v;
        e[i].u = u;
        e[i].v = v;
    }

    cin>> q;
    FORE(i,1,q) cin>> query[i].l >> query[i].r;
}

int cmp(queries a, queries b) {
    if (a.l/k != b.l/k) return a.l < b.l;
    return a.r > b.r;
}

void prepare() {
    k = sqrt(m);

    FORE(i,1,q) query[i].pos = i;
    sort(query+1, query+q+1, cmp);
    query[0].r = m;
    query[0].l = 1;
    lef = 1;

    FORE(i,1,n) color[i] = precolor[i] = i;
    ans = preans = n;
}

int anc(int u) {
    if (color[u] == u) return u;
    else return color[u] = anc(color[u]);
}

void join(int u, int v) {
    if (anc(u) != anc(v)) --ans;
    color[anc(u)] = anc(v);
}

void snapshot() {
    FORE(i,1,n) precolor[i] = color[i];
    preans = ans;
}

void rollback() {
    FORE(i,1,n) color[i] = precolor[i];
    ans = preans;
}

int test(int xx) {
    FORE(x,1,q)
    if (query[x].pos == xx) {
        FORE(i,1,n) color[i] = i;
        ans = n;
        FOR(i,1, query[x].l) join(e[i].u, e[i].v);
        FORE(i,query[x].r+1, n) join(e[i].u, e[i].v);
    }

    int res = ans;

    FORE(i,1,n) color[i] = i;
    ans = n;

    return res;
}

void process() {
    int r;

    //test(1);
    cout<< k <<endl;
    FORE(x,1,q) {
        int t = query[x].l/k;
        if (x == 1 || query[x].l/k != query[x-1].l/k) {

            FORE(i,1,n) color[i] = i;

            ans = n;
            r = n;
            FOR(i,1, t*k) join(e[i].u, e[i].v);
            while(r > query[x].r) join(e[r].u, e[r].v), --r;
            //FORE(i,1,n)
            //cout<< color[i] <<endl;
            //cout<< query[x].l <<' '<< query[x].r <<' '<< ans <<' '<< preans <<' '<<"A"<<endl;

            snapshot();
        }

        while(r > query[x].r) join(e[r].u, e[r].v), --r;
        snapshot();
        //if (query[x].pos == 178)
        //cout<< t*k <<' '<< query[x].r <<' '<< ans <<' '<< preans <<endl;

        FOR(i,t*k, query[x].l) join(e[i].u, e[i].v);
        //if (query[x].pos == 178)
        //cout<< query[x].l <<' '<< query[x].r <<' '<< ans <<' '<< preans <<endl;

        res[query[x].pos] = ans;

        /*if (res[query[x].pos] != test(query[x].pos)) {
            cout<< "WRONG ANSWER: " << query[x].pos <<' '<< x <<' '<< query[x].l <<' '<< query[x].r <<endl;
            cout<< ans <<' '<< test(query[x].pos) <<endl;
            //return;
        }*/
        rollback();

    }

    FORE(i,1,q)
    cout<< res[i] <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("concomp.inp", "r", stdin);
    freopen("concomp.out", "w", stdout);
    #endif
    init();
    prepare();
    process();

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
