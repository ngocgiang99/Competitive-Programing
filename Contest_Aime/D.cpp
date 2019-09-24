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



const int MAXN = 1e5 + 7;
const int base = 1e9 + 7;
const int N = 500;

int n;
int a[MAXN];
int prime[MAXN];
int cc[MAXN], b[N], p[MAXN], y[N], x[N];
int temp, len;
int ans;
int cnt;

void init() {
    cin>> n;
    FORE(i,1,n) cin>> a[i];
}

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

void prepare() {
    int x = sqrt(MAXN);
    FORE(i,2,x)
    if (!prime[i]) {
        for (int j = i * i; j < MAXN; j += i) prime[j] = i;
    }

    FOR(i,2,MAXN)
    if (!prime[i]) prime[i] = i, p[++cnt] = i;//, cerr<< i <<endl;

    //FOR(i,2,MAXN)
    // for (int j = i; j < MAXN; j += i) 
    // if (cc[j]) f[i] = 1;
}

void process1() {
    int ans = 0;
    FORE(i,1,n)
    FORE(j,i+1,n) {
        int gg = gcd(a[i], a[j]);
        long long lcm = 1ll * a[i] * a[j] / gg;
        cerr<< gg <<' '<< lcm <<endl;
        cerr<< a[i] / gg <<' '<< a[j] / gg <<endl;
        ans = (ans + lcm % base) % base;
    }
    // cout<< ans <<endl;
    cerr << ans <<endl;
}

void upd(int X) {    
    int gg = gcd(X, temp);
    cout<< gg <<endl;
    int res = (1ll * X * temp / gg) % base;
    cout<< res <<' '<< cc[temp] <<' '<< temp <<endl;
    ans = (ans + 1ll * res * cc[temp] % base) % base;
}

void Try(int i, int X) {
    y[i] = 1;
    FORE(j, 0, 16) {
        if (j) y[i] = y[i] * b[i];
        if (y[i] > MAXN) break;
        if (1ll * temp * y[i] > MAXN) break;
        x[i] = j;
        temp = temp * y[i];
        if (i < len) Try(i+1, X);
        else upd(X);
        temp /= y[i];
    }
}

void process() {
    prepare();
    long long sum = 0;
    len = cnt;
    FORE(i,1,len) b[i] = p[i];
    // return;
    FORE(i,1,n) {
        int pre = 0;
        len = 0;
        int xx = a[i];
        temp = 1;

        if (a[i] == 1) ans = (ans + sum % base) % base;
        else Try(1, a[i]);
        ++cc[a[i]];
        sum = sum + a[i];
    }
    cout<< ans <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    // freopen("input.inp", "r", stdin);
    // freopen("output.out", "w", stdout);
    #endif
    
    init();
    prepare();
    // process1();
    process();


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}