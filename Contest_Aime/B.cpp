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



const int MAXN = 1e6 * 2 + 50;
const int base = 1e9 + 7;
const int N = 500;

int n, M;
long long ans;
int bit[MAXN];
long long s[MAXN];
vector<long long> v;

int get(int x) {
    int res = 0;
    while(x) {
        res += bit[x]; 
        x -= x&(-x);
    }
    return res;
}

void upd(int x, int val) {
    while(x < MAXN) {
        bit[x] += val;
        x += x&(-x);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    // freopen("input.inp", "r", stdin);
    // freopen("output.out", "w", stdout);
    #endif
    cin>> n >> M;
    FORE(i,1,n) {
        int a;
        cin>> a;
        s[i] = s[i-1] + a;
        v.pb(s[i]);
        v.pb(s[i] - M);
    }
    v.pb(0);
    sort(v.begin(), v.end());

    //int kk = lower_bound()
    int xx = 2 * n + 1;
    FORE(i,1,n) {
        int kk = lower_bound(v.begin(), v.end(), s[i-1]) - v.begin() + 1;
        kk = xx - kk + 1;
        upd(kk, 1); 
        kk = lower_bound(v.begin(), v.end(), s[i] - M) - v.begin() + 1;
        kk = xx - kk + 1;
        ans += get(kk);
    }

    cout << ans <<endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}