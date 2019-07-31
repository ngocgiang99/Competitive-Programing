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
const int N = 5000;

long long x, k;

long long Pow(ll x, ll b) {
    ll res = 1;
    x %= base;
    while(b) {
        if (b&1) res = res*x % base;
        x = x*x % base;
        b >>= 1;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> x >> k;
    if (x == 0) {
        cout<< 0 <<endl;
        return 0;
    }

    ll x1 = x%base;
    ll x2 = Pow(2,k);
    ll ans = x1*Pow(2,2*k+1) % base;
    //cout<< ans <<endl;
    ans = (ans - x2 * (x2 - 1) % base + 1ll*base*base) % base;
    //cout<< ans <<endl;
    ans = ans * Pow(x2, base-2) % base;

    cout<< ans <<endl;
    return 0;
}