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

int n, t;
ll ans, a, b, v, cnt;
ll c[N], x[N];

void upd() {
    ll res = 0;
    FORE(i,1,n) {
        ll p = c[i] * x[i];
        res = res ^ p;
    }

    //FORE(i,1,n)
    //cout<< x[i]*c[i] <<' ';
    //cout<< res <<endl;
    if (res <= v) ans = max(ans, cnt);
}

void Try(int i) {
    FORE(j,0,1) {
        x[i] = j;
        cnt += j;
        if (cnt + n - i > ans) {
            if (i < n) Try(i+1);
            else upd();
        }
        cnt -= j;
    }
}

void process() {
    n = 0;

    ll n1 = a/4;
    while(n1*4 < a) ++n1;
    ll n2 = b/4;

    //cout<< n1 <<' '<< n2 <<endl;
    for(ll i = n1*4-1; i >= a; --i) c[++n] = i;
    if (b%4 != 3) {
        for(ll i = n2*4; i <= b; ++i) c[++n] = i;
    }
    else ++n2;

    if (b - a <= 6) {
        n = 0;
        for(ll i = a; i <= b; ++i) c[++n] = i;
        n1 = 0;
        n2 = 0;
    }


    ans = 0;
    cnt = 0;
    Try(1);

    //cout<< n1 <<' '<< n2 <<endl;
    ans = ans + 4ll*(n2 - n1);
    write(ans);
    putchar('\n');
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    read(t);
    while(t--) {
        read(a); read(b); read(v);

        process();
    }



    return 0;
}