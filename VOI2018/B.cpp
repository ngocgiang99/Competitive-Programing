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

int n;
int a[MAXN], b[MAXN];
ll res;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int prime(int x) {
    if (x < 2) return 0;
    int xx = sqrt(x);
    FORE(i,2,xx)
    if (x%xx == 0) return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("new.inp", "r", stdin);
    //freopen("new.out", "w", stdout);
    #endif
    cin>> n;
    int mx = 0;
    FORE(i,1,n) cin>> a[i] >> b[i], mx = max(mx, a[i], b[i]);

    if(n == 1) {
        res = gcd(a[1], b[1]);
        if (res > 1) cout<< res;
        else cout<< -1;
        return 0;
    }

    FORE(i,1,n) {
        ll xx = gcd(a[i], b[i]);
        ll x = 1ll*a[i]/xx;

        x = x*b[i];
        if (i > 1) res = gcd(res, x);
        else res = x;
    }
    int cnt = 0;
    FORE(i,1,n)
    if (a[i]%res == 0 && b[i]%res == 0) {
        ++cnt;
    }

    if (cnt == n) {
        cout<< res;
        return 0;
    }

    FORE(i,2,sqrt(mx))
    if (prime(i) && res%i == 0) {
        cout<< i;
        return 0;
    }

    cout<< -1;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
