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



const int MAXN = 2e7 + 5;
const int base = 1e9 + 7;
const int N = 1005;

int n, m;
int f[N][N];
int po[MAXN], ipo[MAXN], g[MAXN / 2];

int power(int a, int b) {
    int res = 1;
    while(b) {
        if (b&1) res = 1ll*res*a % base;
        a = 1ll*a*a%base;
        b >>= 1;
    }
    return res;
}

int Ckn(int k, int n) {
    int A = po[n];
    int B = 1ll * ipo[k] * ipo[n-k] % base;

    //cout<< k <<' '<< n <<' '<< A <<' '<< B <<endl;
    return 1ll * A * B % base;
}

void sub12() {
    f[0][0] = 1;
    FORE(i, 1, m) f[i][0] = 1;
    FORE(j, 1, n) f[0][j] = 1;

    FORE(i, 1, m)
    FORE(j, 1, n) {
        int a = (f[i-1][j] + f[i][j-1] ) % base;
        f[i][j] = (a + f[i-1][j-1]) % base;
    }

    cout<< f[m][n] <<endl;
}

void sub3() {
    if (n > m) swap(n, m);
    po[0] = 1;
    FORE(i, 1, n+m) po[i] = 1ll*po[i-1]*i % base;

    int ans = Ckn(n, m+n);
    //cout<< ans <<endl;
    FORE(i,1,n) {
        int nn = n + m - i;
        ans = (ans + 1ll*Ckn(i , nn) * Ckn(n-i, nn-i) % base) % base;
        //cout<< i <<' '<< ans <<' '<< Ckn(i, nn) <<' '<< Ckn(n-i, nn) <<endl;
    }

    cout<< ans <<endl;
}

void sub4() {
    if (n > m) swap(n, m);
    po[0] = 1;
    FORE(i, 1, n+m) po[i] = 1ll*po[i-1]*i % base;
    ipo[m+n] = power(po[m+n], base-2);
    FORD(i, m+n-1, 1) ipo[i] = 1ll * ipo[i+1] * (i+1) % base; 
    ipo[0] = 1;

    int ans = Ckn(n, m+n);
    //cout<< ans <<endl;
    FORE(i,1,n) {
        int x = m + n - i;
        ans = (ans + 1ll * Ckn(i, x) * Ckn(n - i, x - i) % base) % base;
        //cout<< i <<' '<< ans <<' '<< Ckn(i, x) <<' '<< Ckn(n-i, x-i) <<endl;
    }

    cout<< ans <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("ANT.inp", "r", stdin);
    freopen("ANT.out", "w", stdout);

    cin>> m >> n;

    //if (n <= 1000 && m <= 1000) sub12();
    //else 
    //sub3();
    sub4();



    return 0;
}