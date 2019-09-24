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
const int N = 505;

typedef pair<int,int> ii;
int dx[2][3]; //= {(0, 1, 1),
                //(0, 1, 1)};
int dy[2][3]; //= {(1, 0, 1),
               // (-1, 0, -1)};

int n, k;
int ans;
int a[N][N], d[2][N][N];
vector<ii> q[2];

int check(int u, int v) {
    return (1 <= u) & (1 <= v) & (u <= n) & (v <= n);
}

vector<ii> bfs(int x, int step) {
    vector<ii> res;

    FOR(i, 0, q[x].size()) {
        int u = q[x][i].fi;
        int v = q[x][i].se;

        //cout<< x <<' '<< u <<' '<< v <<' '<< step <<' '<< d[x][u][v] <<endl;
        FORE(i,0,2) {
            int u1 = u + dx[x][i];
            int v1 = v + dy[x][i];

            if (!check(u1,v1)) continue;
            if (a[u1][v1]) continue;

            //cout<< u1 <<' '<< v1 <<' '<< d[x][u1][v1] <<endl;
            if (d[x][u1][v1] != step) {
                d[x][u1][v1] = step;
                res.pb(ii(u1,v1));
            }
        }
    }

    return res;
}

void init() {
    dx[0][0] = 0; dx[0][1] = 1; dx[0][2] = 1;
    dx[1][0] = 0; dx[1][1] = 1; dx[1][2] = 1;

    dy[0][0] = 1; dy[0][1] = 0; dy[0][2] = 1;
    dy[1][0] = -1; dy[1][1] = 0; dy[1][2] = -1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("robocon.inp", "r", stdin);
    freopen("robocon.out", "w", stdout);
    #endif
    cin>> n >> k;
    FORE(i,1,k) {
        int u, v;
        cin>> u >> v;
        a[u][v] = 1;
    }

    init();

    q[0].pb(ii(1,1));
    q[1].pb(ii(1,n));
    while(true) {
        ++ans;
        q[0] = bfs(0,ans);
        q[1] = bfs(1,ans);

        FOR(i, 0, q[0].size()) {
            int u = q[0][i].fi;
            int v = q[0][i].se;

            if (d[1][u][v] == ans) {
                cout<< ans <<endl;
                return 0;
            }
        }
    }

    cout<< ans <<endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
