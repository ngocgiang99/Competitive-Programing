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

int n;
int finish;
int a[N][N];
int fx[N], fy[N], check[N], matchx[N], matchy[N];
int vx[N], vy[N];

void bfs(int st) {
    queue<int> q;
    //cout<< q.size() <<endl;
    q.push(st);
    FORE(i,1,n) check[i] = 0;

    while(q.size()) {
        int u = q.front(); q.pop();
        //cout<< u <<' '<< fx[2] <<' '<< fy[1] <<' '<< a[2][1] <<endl;
        FORE(v,1,n)
        if (check[v] == 0 && a[u][v] - fx[u] - fy[v] == 0) {
            check[v] = u;
            //cout<< v <<' '<< check[v] <<endl;
            if (matchy[v] == 0) {
                finish = v;
                return;
            }
            //if (check[matchy[v]] == 0)
            q.push(matchy[v]);
        }
    }
}

void suanhan(int st) {
    FORE(i,1,n) vx[i] = vy[i] = 0;
    vx[st] = 1;
    FORE(v,1,n)
    if (check[v]) {
        vx[matchy[v]] = 1;
        vy[v] = 1;
    }

    int delta = base;

    FORE(u,1,n)
    if (vx[u])
        FORE(v,1,n)
        if (vy[v] == 0) delta = min(delta, a[u][v] - fx[u] - fy[v]);

    FORE(u,1,n) {
        if (vx[u]) fx[u] += delta;
        if (vy[u]) fy[u] -= delta;
    }
}

void update(int finish) {
    int v = finish;
    while(v != 0) {
        int temp = matchx[check[v]];
        matchx[check[v]] = v;
        matchy[v] = check[v];

        //cout<< check[v] <<' '<< v <<' '<< temp <<endl;

        v = temp;
    }
    //cout<<"BUG"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("txt.inp", "r", stdin);
    freopen("txt.out", "w", stdout);
    #endif

    cin>> n;
    FORE(i,1,n)
    FORE(j,1,n) a[i][j] = (i-1)*n + j;

    /*int u, v, w;
    while(cin>> u >> v >> w){
        //cout<< u <<' '<< v <<' '<< w <<endl;
        a[u][v] = w;
        //a[v][u] = w;
    }*/

    FORE(i,1,n) {
        finish = 0;
        while(finish == 0) {
            bfs(i);
            suanhan(i);
        }
        update(finish);
    }

    int ans = 0;
    FORE(i,1,n)
    ans += a[i][matchx[i]];

    //cout<< a[3][4] <<endl;
    cout<< ans <<endl;
    FORE(i,1,n)
    cout<< i <<' '<< matchx[i] <<endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
