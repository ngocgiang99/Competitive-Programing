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

int m, n, h;
int a[N], b[N], c[N][N], res[N][N];
int u[N], v[N], row[N], col[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("new.inp", "r", stdin);
    //freopen("new.out", "w", stdout);
    #endif
    cin>> m >> n >> h;
    FORE(i,1,n) cin>> a[i];
    FORE(i,1,m) cin>> b[i];
    FORE(i,1,m)
    FORE(j,1,n) cin>> c[i][j];

    FORE(i,1,m) {
        FORE(j,1,n) u[i] += c[i][j];
    }

    FORE(j,1,n) {
        FORE(i,1,m) v[j] += c[i][j];
    }

    FORE(i,1,m){
        FORE(j,1,n)
        if (c[i][j]) {
            //cout<< i <<' '<< j <<endl;
            if (u[i] == 1) {
                res[i][j] = b[i];
                row[i] = 1;
                continue;
            }
            if (v[j] == 1) {
                res[i][j] = a[j];
                col[j] = 1;
                continue;
            }

            res[i][j] = min(b[i], a[j]);

            /*if (row[i]) {
                res[i][j] = b[i];
                row[i] = 1;
            }
            else if (col[j]) {
                res[i][j] = a[j];
                col[j] = 1;
            }
            else {
                res[i][j] = b[i];
            }*/
        }
    }

    FORE(i,1,m) {
        FORE(j,1,n) cout<< res[i][j] <<" ";
        cout<< '\n';
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
