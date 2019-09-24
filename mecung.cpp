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



const int MAXN = 1e5 + 50;
const int base = 1e9 + 7;
const int N = 5000;


int n, m;
int d[MAXN], t[MAXN], cl[MAXN], ans[MAXN], cx[MAXN];
queue<int> q;
vector<int> a[MAXN], c[MAXN];

void bfs() {
    q.push(1);
    while(q.size()) {
        int u = q.front(); q.pop();

        //cout<< u <<endl;
        for(int i = 0; int v = a[u][i]; ++i)
        if (d[v] > d[u] + 1 && cx[v] == 0) {
            d[v] = d[u] + 1;
            t[v] = u;
            cl[v] = c[u][i];
            cx[v] = 1;
            q.push(v);
        }
        else
        if (d[v] == d[u] + 1) {
            if (cl[v] > c[u][i]) {
                t[v] = u;
                cl[v] = c[u][i];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("new.inp", "r", stdin);
    //freopen("new.out", "w", stdout);
    #endif
    read(n); read(m);
    FORE(i,1,m) {
        int u, v, cc;
        read(u); read(v); read(cc);
        a[u].pb(v); c[u].pb(cc);
        a[v].pb(u); c[v].pb(cc);
    }

    FORE(i,1,n) a[i].pb(0);
    FORE(i,2,n) d[i] = base;

    bfs();

    cout<< d[n] <<endl;
    int v = n;
    FORD(i,d[n],1){
        ans[i] = cl[v];
        v = t[v];
    }

    FORE(i,1,d[n])
    cout<< ans[i] <<' ';

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
