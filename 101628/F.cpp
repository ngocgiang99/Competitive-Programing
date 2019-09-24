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
const int N = 5000;
typedef pair<long long,int> ii;

int n, m, K, P;
int p[MAXN];
long long T;
long long d[MAXN];
vector<int> a[MAXN], c[MAXN];
priority_queue<ii> h;

void dijkstra() {
    FORE(i,1,n) d[i] = 1e15;
    d[1] = 0;
    h.push(ii(0,1));
    while(h.size()) {
        long long du = -h.top().fi;
        int u = h.top().se;
        h.pop();

        if (du != d[u]) continue;
        //cout<< u <<' '<< d[u] <<endl;
        //if (du > T) return;
       // if (u == n) return;

        
        for(int i = 0; int v = a[u][i]; ++i) {
            int cp = 0;
            if (p[v]) cp = K;
            //cout<< u <<' '<< v <<endl;
            if (d[v] > d[u] + c[u][i] + cp) {
                d[v] = d[u] + c[u][i] + cp;
                h.push(ii(-d[v], v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> n >> m >> T >> K >> P;
    FORE(i,1,P) {
        int x;
        cin>> x;
        p[x] = 1;
    }

    FORE(i,1,m) {
        int u, v, w;
        cin>> u >> v >> w;
        a[u].pb(v); c[u].pb(w*60);
        //a[v].pb(u); c[v].pb(w*60);
    }
    
    FORE(i,1,n) a[i].pb(0);
    T = T*60;
    //cout<< T <<endl;

    dijkstra();

    if (d[n] <= T) cout<< d[n];
    else cout<< -1;

    return 0;
}