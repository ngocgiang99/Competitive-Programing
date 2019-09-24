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

int n, ans, k;
int a[MAXN], b[MAXN], pos[MAXN], ok[MAXN];
vector<int> v[MAXN];
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
    #endif

    cin>> k >> n;
    FORE(i,1,n) {
        cin>> a[i] >> b[i];
        v[a[i]].pb(i);
        v[b[i]].pb(i);
    }

    // FORE(i,1,n) pos[i] = 1;
    FORE(i,1,n)
    if (!ok[i]) {
        q.push(i);
        while(q.size()) {
            int u = q.front(); q.pop();
            // cout<< u <<' '<< q.size() <<endl;
            if (ok[u]) continue;
            ok[u] = 1;
            if (pos[a[u]] && pos[b[u]]) ++ans;
            else {
                if (!pos[a[u]]) {
                    int x = a[u];
                    FOR(i, 0, v[x].size())
                    if (!ok[v[x][i]]) {
                        q.push(v[x][i]);
                    }
                }
                if (!pos[b[u]]) {
                    int x = b[u];
                    FOR(i, 0, v[x].size())
                    if (!ok[v[x][i]]) {
                        q.push(v[x][i]);
                    }
                }
            }
            pos[a[u]] = 1;
            pos[b[u]] = 1;
        }
    }

    cout<< ans <<endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}