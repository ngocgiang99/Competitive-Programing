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



const int MAXN = 1e5 * 2 + 50;
const int base = 1e9 + 7;
const int N = 5000;

int n, q;
int a[MAXN], rmq[MAXN][20], pre[MAXN];

int get(int l, int r) {
    if (l > r) return base;
    int k = log2(r - l + 1);
    return min(rmq[l][k], rmq[r - (1<<k) + 1][k]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("new.inp", "r", stdin);
    //freopen("new.out", "w", stdout);
    #endif
    cin>> n >> q;
    FORE(i,1,n) cin>> a[i];

    int dd = 0;
    FORE(i,1,n)
    if(a[i] != 0 && a[i] != q) {
        ++dd;
    }
    if (dd == n) {
        cout<< "NO";
        return 0;
    }

    FORE(i,1,n)
    if (a[i]) rmq[i][0] = a[i];
    else rmq[i][0] = base;

    int k = log2(n);
    FORE(j,1,k) {
        FORE(i,1,n) {
            if (i + (1<<j) - 1 > n) break;
            rmq[i][j] = min(rmq[i][j-1] , rmq[i + (1<<(j-1))][j-1]);
        }
    }

    FORE(i,1,n) {
        if (pre[a[i]] != 0 && get(pre[a[i]] + 1, i-1) < a[i]) {
            //cout<< pre[a[i]] + 1 <<' '<< i-1 <<' '<< get(pre[a[i]] + 1, i-1) <<endl;
            cout<< "NO";
            return 0;
        }
        pre[a[i]] = i;
    }

    cout<< "YES" <<endl;

    FORE(i,1,n)
    if (a[i] != 0) {
        a[0] = a[i];
        break;
    }

    int cnt = 0;
    FORE(i,1,n)
    if (a[i] != q) {
        ++cnt;
    }

    if (cnt == n)
    FORE(i,1,n)
    if (a[i] == 0) {
        a[i] = q;
        break;
    }

    FORE(i,1,n) {
        if (a[i] == 0) a[i] = a[i-1];
        cout<< a[i] <<' ';
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
