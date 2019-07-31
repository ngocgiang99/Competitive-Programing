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


int len, n, m, res, ans;
int c[N], b[N];
pair<int, int> a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("988f.inp", "r", stdin);
    //freopen("new.out", "w", stdout);
    #endif
    cin>> len >> n >> m;
    FORE(i,1,n) {
        int l, r;
        cin>> l >> r;
        c[l] = 1;
        c[r] = 3;
        FOR(j,l+1,r) c[j] = 2;
    }
    FORE(i,1,m) cin>> a[i].fi >> a[i].se;
    FORE(i,1,len) c[i] += c[i-1];
    sort(a+1, a+m+1);


    int dau = len+1;
    FORD(x,len,0) {
        if (c[x] == 2) b[x] = base, dau = x;
        else {
            b[x] = b[x+1];
            FORE(i,1,m)
            if (a[i].fi > x ) {
                if (a[i].fi >= dau) break;
                b[x] = min(b[x], a[i].se);
            }
        }
    }
    a[m+1].fi = base;
    int pos = 1;
    int res = base;
    FORE(x,0,len) {
        while(a[pos].fi <= x) {
            res = min(res, a[pos].se);
            ++pos;
        }
        if (pos == 1 && c[x]) {
            cout<< -1;
            return 0;
        }

        if (res >= b[x]) res = base;

        cout<< x <<' '<< res <<' '<< b[x] <<' '<< a[1].se <<endl;
        if (res != base)
        ans += res;
    }
    cout<< ans <<endl;




    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
