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

int n, m, n1;
int a[N], x[N];
vector<int> v;
long long ans;

void upd(int mx) {
    if (mx == n1) {
        int tmp = 0;
        FORE(i,1,n1)
        tmp += a[i] * x[i];
        v.pb(tmp);
    }
    else {
        int tmp = 0;
        FORE(i,n1+1, n) 
        tmp += a[i] * x[i];

        int ln = upper_bound(v.begin(), v.end(), m - tmp) - v.begin();
        // FORE(i, n1+1, n)
        // cout<< x[i] <<' ';
        // cout<<endl;
        // cout << ln <<endl;
        ans += ln;
    }
}

void Try(int i, int mx) {
    FORE(j, 0, 1) {
        x[i] = j;
        if (i < mx) Try(i+1, mx);
        else upd(mx);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    // freopen("input.inp", "r", stdin);
    // freopen("output.out", "w", stdout);
    #endif

    cin>> n >> m;
    FORE(i,1,n) cin>> a[i];
    
    n1 = n / 2;

    Try(1, n1);
    sort(v.begin(), v.end());
    Try(n1+1, n);

    cout<< ans <<endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}