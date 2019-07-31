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
const int N = 1000 + 5;


struct data {
    int u, v, x;
    data() {u = v = x = 0;}
    data(int _u, int _v, int _x) {
        this->u = _u;
        this->v = _v;
        this->x = _x;
    }
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int a, b, c, m, n, k;
int f[N][N][7], mask[N][N], cost[N][N], ans[N][N];
int s[N][N];
data p[N];
queue<data> q;


void init() {
    read(a); read(b); read(c);
    read(m); read(n);
    read(k);

    FORE(i,1,k) {
        int x, y;
        read(x); read(y);
        cost[x][y] = 1;
    }
}

int getsum(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
}

int split(int x, int h) {
    int aa = p[x].u;
    int bb = p[x].v;
    int cc = p[x].x;

    if (h == 0 || h == 2) return mask[cc][bb];
    else
        return mask[aa][cc];
}

int check(int u, int v) {
    return (1 <= u) & (1 <= v) & (u <= m) & (v <= n);
}

void prepare() {
    FORE(i,1,m)
    FORE(j,1,n) {
        s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + cost[i][j];
    }

    mask[a][b] = 1; mask[b][a] = 2;
    mask[a][c] = 3; mask[c][a] = 4;
    mask[b][c] = 5; mask[c][b] = 6;

    p[1] = data(a,b,c); p[2] = data(b,a,c);
    p[3] = data(a,c,b); p[4] = data(c,a,b);
    p[5] = data(b,c,a); p[6] = data(c,b,a);
}

void bfs() {
    q.push(data(1,1,mask[a][b]));
    f[1][1][mask[a][b]] = 1;

    while(q.size()) {
        int u = q.front().u;
        int v = q.front().v;
        int x = q.front().x;
        q.pop();


        FORE(i,0,3) {
            int u1 = u + dx[i];
            int v1 = v + dy[i];

            if (!check(u1,v1)) continue;
            if (!check(u1+p[x].u-1, v1+p[x].v-1)) continue;

            if (getsum(u1, v1, u1+p[x].u-1, v1+p[x].v-1) == 0 && f[u1][v1][x] == 0 ) {
                q.push(data(u1, v1, x));
                f[u1][v1][x] = 1;
            }
        }

        FORE(i,0,3) {
            int u1 = u,v1 = v;
            if (i == 0) u1 = u - p[x].x;
            if (i == 1) v1 = v + p[x].v;
            if (i == 2) u1 = u + p[x].u;
            if (i == 3) v1 = v - p[x].x;

            int xx = split(x, i);

            if (!check(u1,v1)) continue;
            if (!check(u1+p[xx].u-1, v1+p[xx].v-1)) continue;

            if (getsum(u1, v1, u1+p[xx].u-1, v1+p[xx].v-1) == 0 && f[u1][v1][xx] == 0 ) {
                q.push(data(u1, v1, xx));

                f[u1][v1][xx] = 1;
            }
        }
    }
}

void process() {
    bfs();
    FORE(i,1,m)
    FORE(j,1,n)
    FORE(x,1,6)
    if (f[i][j][x]) {
        int aa = p[x].u;
        int bb = p[x].v;

        ++ans[i][j];
        ++ans[i+aa][j+bb];
        --ans[i+aa][j];
        --ans[i][j+bb];
    }

    int cnt = 0;
    FORE(i,1,m)
    FORE(j,1,n) {
        ans[i][j] = ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1] + ans[i][j];
        if (ans[i][j]) ++cnt;
    }


    cout<< cnt <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("blgame.inp", "r", stdin);
    freopen("blgame.out", "w", stdout);
    #endif
    init();
    prepare();
    process();


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
