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



const int MAXN = 1e6 + 5;
const int base = 1e9 + 7;
const int N = 5000;

int n;
int po[MAXN], poo[MAXN];

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
    //freopen("COUPLE.inp", "r", stdin);
    //freopen("COUPLE.out", "w", stdout);

    cin>> n;
    long long ans = 0;
    po[0] = 1;
    FORE(i,1,n) po[i] = 1ll * po[i-1] * i % base;

    poo[0] = 1;
    poo[1] = 1;
    for (int i = 3; i <= n; i += 2) poo[i] = 1ll * poo[i-2] * i % base; 
    

    for (int i = n&1; i <= n; i += 2) {
        if (i == n) ans++;
        else {
            int t = 1ll * Ckn(i, n) * poo[n-i-1] % base;
            t = 1ll * t * poo[n-i-1] % base;
            //cout<< i <<' '<< t <<endl;
            ans = (ans + t) % base;
        }
    }
    
    cout<< ans <<endl;


    return 0;
}