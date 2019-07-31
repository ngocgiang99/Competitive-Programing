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



const int MAXN = 1e6 + 7;
const int base = 998244353;
const int N = 5000;

int n;
int a[MAXN], s[MAXN], f[MAXN];

int add(int a, int b) {
    a += b;
    if (a >= base) a -= base;
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("new.inp", "r", stdin);
    //freopen("new.out", "w", stdout);
    #endif
    cin>> n;
    FORE(i,1,n) cin>> a[i];

    FORE(i,1,n) s[i] = add(s[i-1], a[i]);

    int ans = 0;
    int abc = 0;
    int pre1 = 0;
    int pre2 = 0;
    int pre = 0;
    FORE(i,1,n) {
        pre = add(pre, pre1);
        pre1 = s[i];

        int res = add(pre, pre1);

        f[i] = res;
        //cout<< i <<' '<< f[i] <<' '<< pre <<' '<< pre1 <<endl;

        pre = add(pre, pre);
    }

    FORE(i,1,n) {
        f[i] = add(f[i], ans);
        ans = add(ans, f[i]);
    }

    cout<< f[n] <<endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
