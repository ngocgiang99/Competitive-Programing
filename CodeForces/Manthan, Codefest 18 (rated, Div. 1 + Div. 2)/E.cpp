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
const int N = 5000;

struct edges {
    int u, v;
}e[MAXN];

int n, m, k;
int adj[MAXN], ans[MAXN], used[MAXN], usedEdge[MAXN];
vector<int> a[MAXN], c[MAXN];
queue<int> q;

void init() {
    cin>> n >> m >> k;
    FORE(i,1,m) {
        cin>> e[i].u >> e[i].v;

        a[e[i].u].pb(e[i].v); c[e[i].u].pb(i);
        a[e[i].v].pb(e[i].u); c[e[i].v].pb(i);
    }
}

void prepare() {
    FORE(i,1,n) adj[i] = a[i].size();//, cout<< i <<' '<< adj[i] <<endl;

    FORE(i,1,n)
    if (adj[i] < k) q.push(i);

    while(q.size()) {
        int u = q.front(); q.pop();
        used[u] = 1;
        //cout<< u <<endl;

        FOR(i,0,a[u].size()) {
            int v = a[u][i];

            int ind = c[u][i];
            usedEdge[ind] = 1;

            --adj[v];

            if (adj[v] < k && used[v] == 0) {
                q.push(v);
                used[v] = 1;
            }
        }
    }


}

void process() {
    int cnt = 0;

    FORE(i,1,n)
    cnt += (adj[i] >= k);

    ans[m] = cnt;

    int p = m;
    while(m) {
        //cout<< m <<' '<< cnt <<' '<< "ANS" <<endl;
        if (usedEdge[m]) {
            ans[m-1] = cnt;
            --m;
            continue;
        }
        --adj[e[m].u];
        --adj[e[m].v];
        usedEdge[m] = 1;

        if (adj[e[m].u] < k && used[e[m].u] == 0) q.push(e[m].u), used[e[m].u] = 1;
        if (adj[e[m].v] < k && used[e[m].v] == 0) q.push(e[m].v), used[e[m].v] = 1;

        while(q.size()) {
            int u = q.front(); q.pop();
            used[u] = 1;
            --cnt;
            //cout<< cnt <<' '<< u <<' '<< m <<endl;

            FOR(i,0,a[u].size()) {
                int v = a[u][i];

                int ind = c[u][i];
                if (usedEdge[ind]) continue;
                usedEdge[ind] = 1;

                --adj[v];
                //cout<< u <<' '<< v <<' '<< adj[v] <<' '<< ind <<endl;
                if (adj[v] < k && used[v] == 0) {
                    q.push(v);
                    used[v] = 1;
                }
            }
        }
        ans[m-1] = cnt;
        m--;
    }

    FORE(i,1,p)
    cout<< ans[i] <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("new.inp", "r", stdin);
    //freopen("new.out", "w", stdout);
    #endif

    init();
    prepare();
    process();

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
