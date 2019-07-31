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

int n, m, s;
int cl[MAXN];
vector<int> a[MAXN], ar[MAXN];


void dfs(int u, int p) {
    cl[u] = 1;

    for(int i = 0; int v = a[u][i]; ++i)
    if (!cl[v]) dfs(v, u);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> n >> m >> s;
    FORE(i,1,m) {
        int u, v;
        cin>> u >> v;
        a[u].pb(v);
        ar[v].pb(u);
    }

    FORE(i,1,n) a[i].pb(0);

    dfs(s, -1);


    int ans = 0;
    FORE(i,1,n)
    if (!cl[i] && ar[i].size() == 0) {
        ++ans;
        dfs(i, -1);
    }

    FORE(i,1,n)
    if (!cl[i]) {
        ++ans;
        dfs(i, -1);
    }

    cout<< ans <<endl;


    return 0;
}