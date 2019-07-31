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
    x = 0; char c; G dau = 1;
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

int m, n, q;
int b[N][N];
long long a[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("table.inp", "r", stdin);
    freopen("table.out", "w", stdout);

    read(m); read(n); read(q);
    FORE(i,1,m)
    FORE(j,1,n) read(b[i][j]);

    while(q--) {
        int x1, x2, y1, y2, val;
        read(x1); read(y1); read(x2); read(y2); read(val);

        a[x1][y1] += val;
        a[x1][y2+1] -= val;
        a[x2+1][y1] -= val;
        a[x2+1][y2+1] += val;
    }

    FORE(i,1,m) {
        FORE(j,1,n) {
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + a[i][j];
            long long ans = a[i][j] + b[i][j];
            if (ans < 0) putchar('-');
            write(abs(ans));
            putchar(' ');
        }
        putchar('\n');
    }


    return 0;
}