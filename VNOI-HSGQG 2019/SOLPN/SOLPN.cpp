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
const int N = 1005;

int get(int x1, int y1, int x2, int y2);

int m, n, q;
int a[N][N], s[N][N];


void input() {
    cin>> m >> n;
    FORE(i,1,m)
    FORE(j,1,n) {
        cin>> a[i][j];
        a[i+m][j] = a[i][j+n] = a[i+m][j+n] = a[i][j];
    }
}

void prepare() {
    FORE(i,1,2*m)
    FORE(j,1,2*n) s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
}

void printarr(int u, int v) {
    cout<< u <<' '<< v <<endl;
    FORE(i,u,u+m-1) {
        FORE(j,v,v+n-1) cout<< a[i][j] <<' ';
        cout<<endl;
    }
    cout<<endl;
}

void process() {

    int u = 1, v = 1;
    
    cin>> q;
    while(q--) {
        int ans;
        cin>> ans;
        //printarr(u, v);

        if (ans) {
            int x1, y1, x2, y2;
            cin>> x1 >> y1 >> x2 >> y2;
            x1 = x1 + u - 1;
            y1 = y1 + v - 1;
            x2 += u-1;
            y2 += v-1;
            cout<< get(x1, y1, x2, y2) <<endl;
        }
        else {
            int x, y;
            cin>> y >> x;
            u = (u - 1 + x)%m + 1;
            v = (v - 1 + y)%n + 1;
        }
    }
}

int get(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("SOLPN.inp", "r", stdin);
    freopen("SOLPN.out", "w", stdout);

    input();
    prepare();
    process();

    return 0;
}