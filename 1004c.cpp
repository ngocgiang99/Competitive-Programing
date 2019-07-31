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

int n;
int sl;
int a[MAXN], last[MAXN], first[MAXN], cnt[MAXN], c[MAXN];
long long ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("new.inp", "r", stdin);
    //freopen("new.out", "w", stdout);
    #endif

    cin>> n;

    int mx = 0;
    FORE(i,1,n) {
        cin>> a[i];
        if (!first[a[i]]) first[a[i]] = i;
        last[a[i]] = i;
        if (!cnt[a[i]]) ++sl;
        ++cnt[a[i]];

        mx = max(mx, a[i]);
    }

    FORE(i,1,mx) c[i] = cnt[i];

    int m = sl;
    FORE(i,1,n) {
        if (i == first[a[i]]) ans += (m-1);
        --c[a[i]];
        
        if (c[a[i]] == 0) --m;
    }

    //cout<< ans <<endl;

    /*FORE(i,1,mx) c[i] = cnt[i];
    m = sl;

    FORD(i,n,1) {
        if (i == last[a[i]]) ans += (m-1);
        --c[a[i]];

        if (c[a[i]] == 0) --m;
    }*/

    FORE(i,1,mx)
    if (cnt[i] > 1) ans++;

    cout<< ans <<endl;


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
