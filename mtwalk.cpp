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
const int N = 300;

typedef pair<int,int> ii;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
int a[N][N], d[N][N], g[N][N];

int check(int u, int v) {
    return (1 <= u) & (1 <= v) & (u <= n) & (v <= n);
}

int bfs(int l, int r) {
    FORE(i,1,n)
    FORE(j,1,n) d[i][j] = base, g[i][j] = 0;
    queue<ii> q;

    if (l <= a[1][1] && a[1][1] <= r)
    q.push(ii(1,1));
    d[1][1] = 0;
    g[1][1] = 1;
    while(q.size()) {
        int u = q.front().fi;
        int v = q.front().se;
        q.pop();

        if (u == n && v == n) return 1;

        FORE(i,0,3){
            int u1 = u + dx[i];
            int v1 = v + dy[i];
            if (check(u1,v1) && l <= a[u1][v1] && a[u1][v1] <= r && d[u1][v1] > d[u][v] + 1) {
                d[u1][v1] = d[u][v] + 1;
                if (g[u1][v1] == 0) {
                    q.push(ii(u1,v1));
                    g[u1][v1] = 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("new.inp", "r", stdin);
    //freopen("new.out", "w", stdout);
    #endif
    cin>> n;
    FORE(i,1,n)
    FORE(j,1,n) cin>> a[i][j];

    FORE(h,0,110)
    FORE(l,0,110-h)
    if (bfs(l, l+h)) {
        cout<< h <<endl;
        return 0;
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
