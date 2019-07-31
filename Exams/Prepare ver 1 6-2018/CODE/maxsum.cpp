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

int n, k;
int a[MAXN];
long long s[MAXN], f[MAXN];
deque<long long> dq;

void init() {
    cin>> n >> k;
    FORE(i,1,n) cin>> a[i];
}

void prepare() {
    FORE(i,1,n) s[i] = s[i-1] + a[i];
    
    dq.pb(0);
    FORE(i,1,k) {
        f[i] = s[i];

        while(dq.size() && f[i] - s[i+1] >= f[dq.back()] - s[dq.back()+1]) dq.pop_back();
        dq.push_back(i);
    }
}

void process() {
    
    FORE(i,k+1,n) {
        while(dq.size() && i - dq.front() - 1 > k) dq.pop_front();

        f[i] = f[dq.front()] + s[i] - s[dq.front()+1];
        //cout<< i <<' '<< dq.front() <<endl;

        while(dq.size() && f[i] - s[i+1] >= f[dq.back()] - s[dq.back()+1]) dq.pop_back();
        dq.push_back(i);
    }
    
    cout<< f[n] <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("maxsum.inp", "r", stdin);
    freopen("maxsum.out", "w", stdout);
    #endif
    init();
    prepare();
    process();


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
