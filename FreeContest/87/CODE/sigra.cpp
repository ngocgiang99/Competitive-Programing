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

int n, m;
int ans, cnt;
int Num[MAXN], Low[MAXN];
vector<int> a[MAXN];

void dfs(int u, int p) {
    Num[u] = Low[u] = ++cnt;

    for(int i = 0; int v = a[u][i]; ++i) 
    if (v != p){
        if (Num[v]) Low[u] = min(Low[u], Low[v]);
        else {
            dfs(v, u);
            Low[u] = min(Low[u], Low[v]);

            if (Low[v] >= Num[v]) {
                //cout<< u <<' '<< v <<endl;
                ++ans;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("sigra.inp", "r", stdin);
    freopen("sigra.out", "w", stdout);
    cin>> n >> m;
    FORE(i,1,m) {
        int u, v;
        cin>> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    FORE(i,1,n) a[i].pb(0);

    dfs(1, -1);

    cout<< ans <<endl;

    return 0;
}