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
const int N = 1e4 + 5;

typedef pair<int, int> ii;

int n, q;
vector<int> a[4*N];
bitset<N> res, b;

void build(int x, int l, int r, int il, int ir, int value) {
    if (r < il || l > ir) return;
    if (il <= l && r <= ir) {
        a[x].pb(value);
        return;
    }
    int mid = (l + r) >> 1;
    build(x + x, l, mid, il, ir, value);
    build(x + x + 1, mid+1, r, il, ir, value);
}

void process(int x, int l, int r, bitset<N> b) {
    FOR(i,0,a[x].size())
    b |= (b << a[x][i]);

    if (l == r) {
        res |= b;
        return;
    }
    int mid = (l + r) >> 1;
    process(x + x, l, mid, b);
    process(x + x + 1, mid+1, r, b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("981e.inp", "r", stdin);
    //freopen("new.out", "w", stdout);
    #endif
    cin>> n >> q;
    FORE(i,1,q) {
        int l, r, x;
        cin>> l >> r >> x;
        build(1,1,n,l,r,x);
    }
    b.set(0);
    process(1,1,n,b);
    int cnt = 0;
    FORE(i,1,n)
    if (res[i]) ++cnt;
    cout<< cnt <<endl;
    FORE(i,1,n)
    if(res[i]) cout<< i <<' ';

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
