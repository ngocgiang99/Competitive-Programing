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



const int MAXN = 1e5 * 5;
const int base = 1e9 + 7;
const int N = 1005;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;

int n, m, q;
int f[N][N];
vector<int> a[N], c[N];
priority_queue<iii> h;

void dijkstra() {
    
    FORE(i,1,n)
    FORE(j,0,1000) f[i][j] = base;
    f[1][0] = 0;
    h.push(iii(0,ii(1,0)));
    while(h.size()) {
        int du = -h.top().fi;
        ii u = h.top().se;
        h.pop();
        if (f[u.fi][u.se] != du) continue;
        if (u.se == 1000) continue;

        //cout<< u.fi <<' '<< u.se <<endl;
        for(int i = 0; int v = a[u.fi][i]; ++i)
        if (f[v][u.se+1] > f[u.fi][u.se] + c[u.fi][i]) {
            f[v][u.se+1] = f[u.fi][u.se] + c[u.fi][i];
            h.push(iii(-f[v][u.se+1], ii(v, u.se+1)));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> n >> m;
    FORE(i,1,m) {
        int u, v, w;
        cin>> u >> v >> w;
        a[u].pb(v); c[u].pb(w);
        //a[v].pb(u); c[v].pb(w);
    }

    FORE(i,1,n) a[i].pb(0);

    dijkstra();
    FORE(i,1,n)
    FORE(j,1,1000) f[i][j] = min(f[i][j], f[i][j-1]);

    cin>> q;
    while(q--) {
        int u, k;
        cin>> u >> k;
        if (f[u][k+1] != base)
            cout<< "=] "<< f[u][k+1] <<endl;
        else cout<< "=[" <<endl;
    }

    return 0;
}

