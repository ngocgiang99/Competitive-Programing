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



const int MAXN = 1e5 * 5;
const int base = 1e9 + 7;
const int N = 5000;

int n, m, n1;
int x[N], a[N];
map<int, int> ma;
long long ans;


void update(int mx) {
    if (mx == n1) {
        int res = m;
        FORE(i, 1, n1) {
            if (x[i] == 1) res += a[i];
            if (x[i] == 2) res -= a[i];
        }
        //cout<< res <<endl;
        ++ma[res];
    }
    else {
        int res = 0;
        FORE(i, n1+1, n) {
            if (x[i] == 1) res += a[i];
            if (x[i] == 2) res -= a[i];
        }
        //cout<< res <<' '<< ma[-res] <<endl;
        ans += ma[-res];
    }
}

void backtrack(int i, int mx) {
    FORE(j, 0, 2) {
        x[i] = j;
        if (i < mx) backtrack(i+1, mx);
        else update(mx);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("BALANCE.inp", "r", stdin);
    freopen("BALANCE.out", "w", stdout);

    cin>> n >> m;
    FORE(i,1,n) cin>> a[i];

    n1 = n/2;
    backtrack(1, n1);
    backtrack(n1+1, n);

    cout<< ans <<endl;

    return 0;
}