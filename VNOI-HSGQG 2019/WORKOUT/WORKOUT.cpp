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
const int N = 12;

void dijkstra(int ind);
int getbit(int bitmask, int i);
int offbit(int bitmask, int i);
void maximize(long long &a, long long b);
typedef pair<int, int> ii;
typedef pair<long long, int> li;
typedef pair<long long, ii> lii;

int n, m, k;
int cnt;
int s[N], t[N], q[N];
long long d[N][MAXN], dr[N][MAXN];
long long f[MAXN][35];
vector<ii> adj[MAXN];
priority_queue<li> h;
priority_queue<lii> heap;

void input() {
    cin>> n >> m >> k;
    FORE(i,1,m) {
        int u, v, w;
        cin>> u >> v >> w;
        adj[u].pb(ii(v,w));
        adj[v].pb(ii(u,w));
    } 

    FORE(i,1,n) adj[i].pb(ii(0,0));
    
    cin>> s[1] >> t[1];
    FORE(i,2,k) {
        cin>> q[i] >> s[i] >> t[i];
    }
}


void prepare() {
    FORE(i,2,k)
    FORE(j,i+1,k)
    if (q[i] < q[j]) {
        swap(q[i], q[j]);
        swap(s[i], s[j]);
        swap(t[i], t[j]);
    }

    FORE(i,2,k)
    if (q[i] == 1) ++cnt;

    FORE(i,1,k) dijkstra(i);
}

void process() {
    int maxBitmask = (1<<cnt) - 1;
    //FORE(i,1,n)
    //FORE(bitmask, 0, maxBitmask) f[i][bitmask] = 1e15;
    //cout<< maxBitmask <<endl;

    FORE(bitmask, 0, maxBitmask) {
        int ok = 1;
        FORE(i,1,cnt)
        if (getbit(bitmask, i)) {
            if (d[i+1][s[1]] + dr[i+1][s[1]] == d[i+1][t[i+1]])  {
                continue;
            }
            else {
                ok = 0;
                break;
            }
        } 

        if (ok == 0) continue;
        f[s[1]][bitmask] = 0;
        heap.push(lii(0, ii(s[1], bitmask)));
    }
    //f[s[1]][0] = 0;
    //heap.push(lii(0, ii(s[1], 0)));
    //cout<< d[4][1] <<' '<< adj[1][1].se <<' '<< dr[4][5] <<endl;
    //cout<< d[4][6] <<endl;

    while(heap.size()) {
        int u = heap.top().se.fi;
        int bitmask = heap.top().se.se;
        long long du = -heap.top().fi;
        heap.pop();

        if (du != d[1][u]) continue;
        
        //cout<< u <<' '<< bitmask <<' '<< f[u][bitmask] <<' '<< d[1][u] <<endl;
        if (u == t[1]) break;

        for(int i = 0; int v = adj[u][i].fi; ++i) {
            int ok = 0;

            int newbitmask = bitmask;
            FORE(j,2,cnt+1)
            if (d[j][u] + adj[u][i].se + dr[j][v] != d[j][t[j]]) newbitmask = offbit(newbitmask, j-1);
            if (newbitmask > 0) ok = 1;

            FORE(j,cnt+2,k)
            if (d[j][u] + adj[u][i].se + dr[j][v] == d[j][t[j]]) {
                ok = 1;
                break;
            }
            //cout<< u <<' '<< bitmask <<' '<< v <<' '<< newbitmask <<' '<< ok <<endl;
            int cost = ok ? adj[u][i].se : 0;

            if (d[1][v] == d[1][u] + adj[u][i].se) {
                maximize(f[v][newbitmask], f[u][bitmask] + cost);
                heap.push(lii(-d[1][v], ii(v, newbitmask)));
            }
        }
    }

    long long ans = 0;
    FORE(bitmask, 0, maxBitmask)
        maximize(ans, f[t[1]][bitmask]);

    cout<< ans <<endl;
}

void maximize(long long &a, long long b) {
    a = max(a, b);
}

void dijkstra(int ind) {
    FORE(i,1,n)
    d[ind][i] = 1e15;
    d[ind][s[ind]] = 0;
    h.push(li(0, s[ind]));

    while(h.size()) {
        int u = h.top().se;
        long long du = -h.top().fi;
        h.pop();

        if (du != d[ind][u]) continue;
        //if (ind == 4)  cout<< u <<' '<< d[ind][u] <<endl;

        for(int i = 0; int v = adj[u][i].fi; ++i) {
            if (d[ind][v] > d[ind][u] + adj[u][i].se) {
                d[ind][v] = d[ind][u] + adj[u][i].se;
                h.push(li(-d[ind][v], v));
            }
        }
    }

    FORE(i,1,n)
    dr[ind][i] = 1e15;
    dr[ind][t[ind]] = 0;
    h.push(li(0, t[ind]));

    while(h.size()) {
        int u = h.top().se;
        long long du = -h.top().fi;
        h.pop();

        if (du != dr[ind][u]) continue;
        //if (ind == 4)  cout<< u <<' '<< dr[ind][u] <<endl;

        for(int i = 0; int v = adj[u][i].fi; ++i) {
            if (dr[ind][v] > dr[ind][u] + adj[u][i].se) {
                dr[ind][v] = dr[ind][u] + adj[u][i].se;
                h.push(li(-dr[ind][v], v));
            }
        }

    }
}

int getbit(int bitmask, int i) {
    return (bitmask >> (i-1)) & 1;
}

int offbit(int bitmask, int i) {
    return (~(1<<(i-1))) & bitmask;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("WORKOUT.inp", "r", stdin);
    freopen("WORKOUT.out", "w", stdout);

    input();
    prepare();
    process();

    return 0;
}