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
const int N = 500;

int n;
int par[N];
char ch[N];
vector<int> a[N];

void init() {
    cin>> ch+1; n = strlen(ch+1);
}

void dfs(int u,int depth,int &res, int &mx) {
    for(int i = 0; int v = a[u][i]; ++i)
    if (par[v] == -1 && v != par[u]) {
        par[v] = u;
        dfs(v, depth + 1, res, mx);
    }

    if (depth > mx) {
        mx = depth;
        res = u;
    }
}

void process() {
    FORE(i,1,n) a[i].clear();
    FORE(i,1,n)
    FORE(j,i+1,n)
    if (abs(ch[i] - ch[j]) != 1) {
        a[i].pb(j);
        a[j].pb(i);
    }
    FORE(i,1,n) a[i].pb(0);
    FORE(i,1,n) par[i] = -1;
    int mx = 0;
    int root;
    dfs(1, 1, root, mx);
    FORE(i,1,n) par[i] = -1;
    int pos;
    dfs(root, 1, pos, mx);

    if (mx == n){
        while(par[pos] != 0) {
            cout<< ch[pos];
            pos = par[pos];
        }
        cout<<endl;
    }
    else {
        
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    int t;
    cin>> t;
    while(t--) {
        init();
        //process();
    }



    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}