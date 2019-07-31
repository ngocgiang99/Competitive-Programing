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



const int MAXN = 1e6 + 10;
const int base = 1e9 + 7;
const int N = 5000;
typedef pair<int,int> ii;

int n;
int a[MAXN], trace[MAXN], f[MAXN], id[MAXN];
vector<int> arr;
ii bit[MAXN];


void maximize(ii &res, ii value) {
    if (value.fi > res.fi) res = value;
    if (value.fi == res.fi) {
        if (a[value.se] > a[res.se]) res.se = value.se;
    }
}

void upd(ii value, int x) {
    while(x <= n) {
        maximize(bit[x], value);
        x += x&(-x);
    }
}

ii get(int x) {
    ii res = ii(0,0);

    while(x) {
        maximize(res, bit[x]);
        x -= x&(-x);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("incseq.inp", "r", stdin);
    freopen("incseq.out", "w", stdout);
    #endif
    read(n);
    FORE(i,1,n) read(a[i]), arr.pb(a[i]);

    sort(all(arr));

    int pos = 0;
    int ans = 0;
    FORE(i,1,n) {
        int x = lower_bound(all(arr), a[i]) - arr.begin() + 1;

        ii ff = get(x-1);
        f[i] = ff.fi + 1;
        trace[i] = ff.se;
        upd(ii(f[i],i), x);

        if (f[i] > ans) {
            ans = f[i];
            pos = i;
        }
        else
        if (f[i] == ans) {
            if (a[i] > a[pos]) pos = i;
        }
    }

    cout<< ans <<endl;
    FORD(i,ans,1) {
        id[i] = pos;
        pos = trace[pos];
    }
    FORE(i,1,ans)
    cout<< a[id[i]] <<endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
