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
const int N = 500;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int m, n;
int a[15][2005];
int pos[MAXN], f[MAXN];
priority_queue<ii> h;

void init() {
    cin>> m >> n;
    FOR(i,0,m)
    FOR(j,0,n) {
        cin>> a[i][j];
        // h.push(iii(a[i][j], ii(i, j)));
    }
}

int getBit(int x, int i) {
    return (x >> (i-1)) & 1;
}

void process() {
    int ans = 0;
    int maxMask = (1 << m);
    
    FORE(x,0,maxMask) f[x] = 0;

    FOR(j,0,n)
    FORD(x, maxMask - 1, 0)
    FOR(y, 0, maxMask)
    if ((x&y) == 0) {
        vector<int> v;
        FORE(i,1,m)
        if (getBit(y, i)) v.pb(i-1);

        // cout<< j << ' '<< x <<' '<< y <<endl;

        int tmp = 0;
        FOR(i, 0, m) {
            int temp = 0;
            FOR(k, 0, v.size())
            temp += a[(i + v[k])%m][j];
            tmp = max(tmp , temp);
        }
        f[x | y] = max(f[x | y], f[x] + tmp);
    }

    cout<< f[maxMask - 1] <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    // freopen("input.inp", "r", stdin);
    // freopen("output.out", "w", stdout);
    #endif
    int t;
    cin>> t;
    while(t--) {
        init();
        process();
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}