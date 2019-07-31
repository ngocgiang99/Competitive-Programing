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
const int N = 152;

int n, m, k;
int ans;
string s;
int a[N], f[N][N][102][N], po[N], pre[N][3], nex[N][3];

void add(int &a, int b) {
    a += b;
    if (a >= m) a -= m;
}

int get(int lef, int rig, int modd, int len) {
    if (f[lef][rig][modd][len] != -1) return f[lef][rig][modd][len];
    if (lef < 1 || rig > n) return modd == 0;

    int res = 0;
    res = get(lef, rig+1, modd, len) + get(lef-1, rig, modd, len) - get(lef-1, rig+1, modd, len);

    if (lef >= 1 && rig <= n && a[lef] == a[rig]) {
        add(res, get(lef-1, rig+1,(a[lef] * po[len+1] + modd*10 + a[lef])%k, len+2));
    }

    f[lef][rig][modd][len] = res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("nkpalin.inp", "r", stdin);
    freopen("nkpalin.out", "w", stdout);
    #endif
    cin>> n >> k >> m;
    cin>> s;
    FORE(i,1,n) a[i] = s[i-1] - '0';

    po[0] = 1;
    FORE(i,1,n) po[i] = po[i-1]*10 % k;

    FORE(i,0,n)
    FORE(j,i,n+1)
    FORE(t,0,k)
    FORE(l,0,n) f[i][j][t][l] = -1;

    FORE(i,0,1) {
        pre[0][i] = 0;
        nex[n+1][i] = n+1;
    }

    FORE(i,1,n) {
        int ii = n-i+1;
        FORE(j,0,1) {
            pre[i][j] = pre[i-1][j];
            nex[ii][j] = nex[ii+1][j];
        }

        pre[i][a[i]] = 1;
        nex[ii][a[ii]] = 1;
    }

    FORE(i,1,n)
    {
        add(ans, get(i-1,i+1,a[i]%k, 1));
    }

    FORE(i,1,n)
    FORE(j,i+1,n)
    if (a[i] == a[j]) {
        add(ans, get(i-1, j+1, a[i]*11 % k, 2));
    }

    cout<< ans <<endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
