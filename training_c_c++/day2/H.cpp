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



const int MAXN = 3e7 + 2;
const int base = 1e9 + 7;
const int N = 5000;

int n, m, k;
int po[MAXN];

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
    int B = 1ll * po[k] * po[n-k] % base;

    B = power(B, base - 2);

    return 1ll * A * B % base;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("BEE.inp", "r", stdin);
    //freopen("BEE.out", "w", stdout);

    cin>> n >> m >> k;
    int n1 = n / 3, m1 = m / 3, k1 = k / 3;

    po[0] = 1;
    FORE(i,1,n+m+k) po[i] = 1ll*po[i-1]*i % base;

    int A = 1ll * Ckn(k1, n1 + m1 + k1) * Ckn(n1, n1 + m1) % base;
    int B = 1ll * Ckn(k - k1, n + m + k - n1 - m1 - k1) * Ckn(n - n1, m + n - m1 - n1) % base;

    long long ans = 1ll * A * B;

    int n2 = 2*n1, m2 = 2*m1, k2 = 2*k1;
    int C = 1ll * Ckn(k2, n2 + m2 + k2) * Ckn(n2, n2 + m2) % base;
    int D = 1ll * Ckn(k - k2, n + m + k - n2 - m2 - k2) * Ckn(n - n2, m + n - m2 - n2) % base;

    ans = (ans + 1ll * C * D) % base;

    int E = (1ll * A * A % base) * D % base;

    ans = (ans - E + 1ll*base*base) % base;

    cout<< ans <<endl;

    return 0;
}