#include <bits/stdc++.h>
using namespace std;
#define FORE(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)

#define fi first
#define se second
#define ll long long
#define mp make_pair
#define pb push_back
#define all(a) a.begin(),a.end()
#define sqr(x) (x)*(x)

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



const int MAXN = 1e4 * 7;
const int base = 1e9 + 7;
const int N = 40;

typedef pair<long long, long long> pll;
int n, m;
int x[N];
long long L, R, ans;
long long w[N], v[N], rmq[MAXN][N/2];
vector<pll> result;

long long maxValue(int l, int r) {
    if (l > r) return 0;
    int k = log2(r - l + 1);
    return max(rmq[l][k], rmq[r - (1<<k) + 1][k]);
}

void update(int mx) {
    if (mx == m) {
        long long sumW = 0, sumV = 0;
        FORE(i, 1, m) 
        if (x[i]) {
            sumW += w[i];
            sumV += v[i];
        }
        if (sumW > R) return;
        result.pb(pll(sumW, sumV));
    }
    else {
        long long sumW = 0, sumV = 0;
        FORE(i, m+1, n) 
        if (x[i]) {
            sumW += w[i];
            sumV += v[i];
        }
        if (sumW > R) return;
        if (sumW + result.back().fi < L) return;

        int indMax = lower_bound(result.begin(), result.end(), pll(R - sumW + 1, 0)) - result.begin() - 1;
        int indMin = lower_bound(result.begin(), result.end(), pll(L - sumW, 0)) - result.begin() ;

        ans = max(ans, sumV + maxValue(indMin, indMax));
    }
}

void backtrack(int i, int mx) {
    FORE(j,0,1) {
        x[i] = j;
        if (i < mx) backtrack(i+1, mx);
        else update(mx);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> n >> L >> R;
    long long maxW = 0;
    FORE(i,1,n) {
        cin>> w[i] >> v[i];
        maxW += w[i];
    }
    if (maxW < L) {
        cout<< 0 <<endl;
        return 0;
    }
    m = n/2;
    backtrack(1, m);
    sort(result.begin(), result.end());

    int mxK = log2(result.size());
    FOR(i, 0, result.size()) rmq[i][0] = result[i].se;
    FORE(k, 1, mxK)
    FOR(i, 0, result.size()) {
        if (i + (1 << k) > result.size()) break;
        rmq[i][k] = max(rmq[i][k-1], rmq[i + (1<<(k-1))][k-1]);
    }

    backtrack(m+1, n);

    cout<< ans <<endl;

    return 0;
}