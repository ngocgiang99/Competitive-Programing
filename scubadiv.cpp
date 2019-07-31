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


int t, n, w1, w2;
int a[N], b[N], w[N];
int f[1002][22][80];

void minimize(int &a, int b) {
    a = min(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("scubadiv.inp", "r", stdin);
    freopen("scubadiv.out", "w", stdout);
    #endif
    cin>> t;
    while(t--) {
        cin>> w1 >> w2;
        cin>> n;
        FORE(i,1,n) cin>> a[i] >> b[i] >> w[i];
        FORE(i,0,n)
        FORE(j,0,w1)
        FORE(k,0,w2) f[i][j][k] = base;

        f[0][0][0] = 0;

        FOR(i,0,n)
        FORE(j,0,w1)
        FORE(k,0,w2)
        if (f[i][j][k] != -1) {
            minimize(f[i+1][min(w1, j+a[i+1])][min(w2, k+b[i+1])], f[i][j][k] + w[i+1]);
            minimize(f[i+1][j][k], f[i][j][k]);
        }

        cout<< f[n][w1][w2] <<endl;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
