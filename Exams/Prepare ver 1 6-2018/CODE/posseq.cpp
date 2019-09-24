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
const int base = 1e9 + 9;
const int N = 5000;

int n;
int s[MAXN], f[MAXN], bit[MAXN];
vector<int> srr;

void upd(int x, int value) {
    while(x <= n) {
        bit[x] = (bit[x] + value)%base;
        x += x&(-x);
    }
}

int get(int x) {
    int res = 0;
    while(x) {
        res = (res + bit[x])%base;
        x -= x&(-x);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("posseq.inp", "r", stdin);
    freopen("posseq.out", "w", stdout);
    #endif  
    cin>> n;
    FORE(i,1,n) {
        int a;
        cin>> a;
        s[i] = s[i-1] + a;
        srr.pb(s[i]);
    }

    srr.pb(0);
    sort(all(srr));

    int xo = lower_bound(all(srr), 0) - srr.begin() + 1;
    upd(xo, 1);
    FORE(i,1,n) {
        int x = lower_bound(all(srr), s[i]) - srr.begin() + 1;

        f[i] = get(x);
        upd(x, f[i]);
    }
    cout<< f[n] <<endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
