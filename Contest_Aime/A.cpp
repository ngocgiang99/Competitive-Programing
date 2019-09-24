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

int n;
pair<int, int> a[MAXN];
vector<int> vb;
int ans;
int bit[MAXN];

int get(int x) {
    int res = 0;
    while(x) {
        res += bit[x];
        x -= x&(-x);
    }
    return res;
}

void update(int x, int val) {
    while(x <= n) {
        // cout << x << ' ' << x + (x & (-x))<<endl;
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
    cin >> n;
    FORE(i,1,n) {
        cin>> a[i].fi >> a[i].se;
        // va.pb(a[i].fi);
        vb.pb(a[i].se);
    }

    sort(a+1, a+n+1);
    sort(vb.begin(), vb.end());
    
    int l = 1;
    FORE(i,1,n) {
        int k = lower_bound(vb.begin(), vb.end(), a[i].se) - vb.begin() + 1;
        k = n - k + 1;
        update(k, 1);
    }

    FORE(i,1,n) {
        while(l <= n && a[l].fi == a[i].fi) {
            int k = lower_bound(vb.begin(), vb.end(), a[l].se) - vb.begin() + 1;
            k = n - k + 1;
            update(k, -1);
            ++l;
        }

        int k = lower_bound(vb.begin(), vb.end(), a[i].se) - vb.begin() + 1;
        k = n - k + 1;

        if (get(k-1) == 0) ++ans, cerr<< i <<endl;
    }
    cout << ans <<endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}