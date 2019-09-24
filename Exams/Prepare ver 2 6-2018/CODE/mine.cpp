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
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do{x = x*10 + c - '0';} while(isdigit(c = getchar()));
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



const int MAXN = 1e5 * 2 + 5;
const int base = 1e9 + 7;
const int N = 5000;

int n, m;
int bit[MAXN];
ll ans;
ll x[MAXN], sg[MAXN], sr[MAXN], a[MAXN], b[MAXN], c[MAXN];

void upd(int x,int value) {
    while(x <= m) {
        bit[x] = min(bit[x], value);
        x += x&(-x);
    }
}

int get(int x) {
    int res = base;
    while(x) {
        res = min(res, bit[x]);
        x -= x&(-x);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("mine.inp", "r", stdin);
    freopen("mine.out", "w", stdout);
    #endif
    cin>> n;
    FORE(i,1,n) {
        int g, r;
        cin>> x[i] >> g >> r;
        //sx[i] = sx[i-1] + x;
        sg[i] = sg[i-1] + g;
        sr[i] = sr[i-1] + r;
    }
    a[++m] = 0;
    FORE(i,1,n) {
        a[++m] = sr[i] - x[i];
        a[++m] = sr[i-1] - x[i];
        b[i] = sr[i] - x[i];
        c[i] = sr[i-1] - x[i];
    }
    sort(a+1, a+m+1);
    FORE(i,1,m) bit[i] = base;
    //cout<< get(5) <<endl;
    int xx = lower_bound(a+1, a+m+1, 0) - a;
    //cout<< xx <<endl;
    upd(xx, 0);
    FORE(i,1,n) {
        int x = lower_bound(a+1, a+m+1, c[i]) - a;
        upd(x, i);
        x = lower_bound(a+1, a+m+1, b[i]) - a;
        int j = get(x);
        //cout<< i <<' '<< x <<' '<< j <<endl;
        if (j != base) ans = max(ans, sg[i] - sg[j-1]);

    }
    cout<< ans <<endl;
    return 0;
}
