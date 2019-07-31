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

int n, m, k;
int ans;
string s;
int a[N], x[N], c[N];

int check(int len) {
    if (len == 0) return 0;
    int lef = 1;
    int rig = len;
    while(lef < rig) {
        if (c[lef] != c[rig]) return 0;
        ++lef;
        --rig;
    }

    return 1;
}

void upd() {
    int xx = 0;
    int len = 0;

    FORE(i,1,n)
    if (x[i]) {
        xx = (xx*10 + a[i]) % k;
        c[++len] = a[i];
        //cout<< len <<' '<< a[i] <<endl;
    }
    if (xx == 0 && check(len)) {
        //FORE(i,1,n)
        //if (x[i]) cout<< a[i];
        //cout<<endl;
        ++ans;
    }
    //cout<< ans <<endl;
}

void duyet(int i) {
    FORE(j,0,1) {
        x[i] = j;
        if (i < n) duyet(i+1);
        else upd();
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("nkpalin.inp", "r", stdin);
    freopen("nkpalin.ans", "w", stdout);
    #endif
    cin>> n >> k >> m;
    cin>> s;

    FORE(i,1,n) a[i] = s[i-1] - '0';

    duyet(1);

    ans %= m;

    cout<< ans <<endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
