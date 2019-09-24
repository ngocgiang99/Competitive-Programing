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
typedef pair<int,int> ii;

int n, m, k;
int Node[MAXN], dmin[MAXN], dmax[MAXN], topo[MAXN], cnt[MAXN];
vector<int> a[MAXN], c[MAXN];
priority_queue<ii> h;


void dijkmin() {
    FORE(i,1,n) dmin[i] = base;
    dmin[1] = Node[1];
    h.push(ii(-dmin[1],1));
    while(h.size()) {
        int du = -h.top().fi;
        int u = h.top().se;
        h.pop();
        //cout<< u <<' '<< h.size() <<endl;
        if (dmin[u] != du) continue;
        //if (u == n) return;
        //cout<< u <<endl;

        for(int i = 0; int v = a[u][i]; ++i)
        if (dmin[v] > dmin[u] + c[u][i]) {
            dmin[v] = dmin[u] + c[u][i];
            h.push(ii(-dmin[v], v));
            //cout<< u <<' '<< v <<' '<< dmin[v] <<' '<< h.size() <<endl;
        }
    }
}

void dijkmax() {
    FORE(u,1,n) {
        for(int i = 0; int v = a[u][i]; ++i)
        ++cnt[v];
    }

    queue<int> q;
    FORE(i,1,n)
    if (cnt[i] == 0) q.push(i);
    
    int cc = 0;
    while(q.size()) { 
        int u = q.front(); q.pop();
        topo[++cc] = u;

        for(int i = 0; int v = a[u][i]; ++i) {
            --cnt[v];
            if (cnt[v] == 0) q.push(v);
        }
    }

    dmax[1] = 1 + Node[1];
    FORE(i,1,n) {
        int u = topo[i];
        if (dmax[u])
            for(int i = 0; int v = a[u][i]; ++i)
            dmax[v] = max(dmax[v], dmax[u] + Node[v]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);


    cin>> n >> k >> m;
    FORE(i,1,k) {
        int x;
        cin>> x;
        Node[x] = 1;
    }

    FORE(i,1,m) {
        int u, v;
        cin>> u >> v;
        a[u].pb(v); 
        if (Node[v]) c[u].pb(1);
        else c[u].pb(0);
    }

    FORE(i,1,n) a[i].pb(0);

    //cout<< 1 <<endl;
    dijkmin();
    dijkmax();
    //cout<< 1 <<endl;
    //cout<<endl;
    cout<< dmin[n] <<' '<< dmax[n]-1 <<endl;
    return 0;
}