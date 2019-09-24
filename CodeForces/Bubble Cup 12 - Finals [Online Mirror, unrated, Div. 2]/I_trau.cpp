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
const int N = 2005;

int n;
int a[N][N], c[N][N], bar[N], b[N][N];
int x[N];
int ok = 0;

void upd() {
    FORE(i,1,n)
    FORE(j,1,n) b[i][j] = a[i][j];

    FORE(i,1,n)
    if (x[i]) {
        FORE(j,1,n)
        b[i][j] ^= bar[j];
    }

    FORE(j,1,n)
    if (x[j + n]) {
        FORE(i,1,n)
        b[i][j] ^= bar[i];
    }

    FORE(i,1,n)
    FORE(j,1,n) 
    if (b[i][j] != c[i][j]) return;
    ok = 1;
    int cnt = 0;
    FORE(i,1,2*n) cnt += x[i];
    cout<< cnt <<endl;
    FORE(i,1,n)
    if (x[i]) cout<< "row " << i-1 <<endl;
    FORE(j,1,n)
    if (x[j + n]) cout<< "col " << j-1 <<endl;
}

void Try(int i) {
    FORD(j, 1, 0) {
        x[i] = j;
        if (i < 2*n) Try(i+1);
        else upd();
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif

    cin>> n;
    FORE(i,1,n)
    FORE(j,1,n) {
        char ch;
        cin>> ch;
        a[i][j] = ch - '0';
    }

    FORE(i,1,n) 
    FORE(j,1,n) {
        char ch;
        cin>> ch;
        c[i][j] = ch - '0';
    }

    FORE(i,1,n) {
        char ch;
        cin>> ch;
        bar[i] = ch - '0';
    }

    Try(1);
    if (!ok) cout<< -1 <<endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}