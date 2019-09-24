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

int m, n;
char a[N][N], ch[N][N];

int check(int u, int v) {
    if (ch[u-1][v-1] == '*') return 0;
    if (ch[u-1][v] == '*') return 0;
    if (ch[u-1][v+1] == '*') return 0;
    if (ch[u][v-1] == '*') return 0;
    if (ch[u][v+1] == '*') return 0;
    if (ch[u+1][v-1] == '*') return 0;
    if (ch[u+1][v] == '*') return 0;
    if (ch[u+1][v+1] == '*') return 0;
    return 1;
}

void colored(int u, int v) {
    a[u-1][v-1] = '#';
    a[u-1][v] = '#';
    a[u-1][v+1] = '#';
    a[u][v-1] = '#';
    a[u][v+1] = '#';
    a[u+1][v-1] = '#';
    a[u+1][v] = '#';
    a[u+1][v+1] = '#';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("signature.inp", "r", stdin);
    freopen("signature.out", "w", stdout);

    cin>> m >> n;
    FORE(i,1,m)
    FORE(j,1,n) cin>> ch[i][j], a[i][j] = '*';

    FORE(i,2,m-1)
    FORE(j,2,n-1)
    if (check(i, j)) colored(i, j);

    int ok = 1;
    FORE(i,1,m)
    FORE(j,1,n)
    if (a[i][j] != ch[i][j]) {
        ok = 0;
    }

    if (ok) cout<< "YES";
    else cout<< "NO";

    return 0;
}
