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

int n, k, s, m;
int cnt;
int vis[MAXN], adj[MAXN];

string ans[MAXN];
map<string, int> Map;
vector<int> a[MAXN];
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("specone.inp", "r", stdin);
    freopen("specone.out", "w", stdout);
    #endif
    cin>> n >> k >> s >> m;
    FORE(i,1,s) {
        string ss;
        cin>> ss;
        if (Map.find(ss) == Map.end()) {
            Map[ss] = ++cnt;
            ans[cnt] = ss;
        }
        q.push(Map[ss]);
        vis[Map[ss]] = 1;
    }
    FORE(i,1,m) {
        string ss1, ss2;
        cin>> ss1;
        if (Map.find(ss1) == Map.end()) {
            Map[ss1] = ++cnt;
            ans[cnt] = ss1;
        }
        cin>> ss2;
        if (Map.find(ss2) == Map.end()) {
            Map[ss2] = ++cnt;
            ans[cnt] = ss2;
        }

        a[Map[ss1]].pb(Map[ss2]);
        a[Map[ss2]].pb(Map[ss1]);
    }

    FORE(i,1,n) a[i].pb(0);

    while(q.size()) {
        int u = q.front(); q.pop();
        vis[u] = 1;

        for(int i = 0; int v = a[u][i]; ++i) {
            if (!vis[v]) {
                ++adj[v];
                if (adj[v] == k) q.push(v);
            }
        }
    }

    int res = 0;

    FORE(i,1,n)
    if (vis[i]) ans[++res] = ans[i];

    sort(ans+1, ans+res+1);

    cout<< res <<endl;

    FORE(i,1,res)
    cout<< ans[i] <<' ';

    /*cout<<endl;
    FORE(i,1,res)
    cout<< Map[ans[i]] <<' ';

    cout<<endl;
    FORE(i,1,n)
    cout<< adj[Map[ans[i]]] <<' ';*/

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
