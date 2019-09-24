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

int n;
int a[MAXN], b[MAXN];

int gcd(int a, int b) {
    if (b == 0) return a;
    else
        return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("C.inp", "r", stdin);
    freopen("C.out", "w", stdout);

    cin>> n;
    int mxb = 0;
    int mxa = 0;
    FORE(i,1,n) cin>> a[i], mxa = max(mxa, a[i]);
    FORE(i,1,n) cin>> b[i], mxb = max(b[i], mxb);

    FORE(i,1,n)
    if (b[i] > a[i]) {
        cout<< -1;
        return 0;
    }

    int x = (a[1] - b[1]);

    FORE(i,2,n) x = gcd(x, a[i] - b[i]);
    //cout<< x <<endl;

    int x_sqrt = sqrt(x);   

    int ans = base;
    FORE(i,1,x_sqrt)
    if (x%i == 0) {
        if (i > mxb) ans = min(ans, i);
        if (x/i > mxb) ans = min(ans, x/i);
    }

    int dem = 0;
    FORE(i,1,n)
    if (a[i] == b[i]) ++dem;
    if (dem == n) ans = min(ans, mxa+1);


    if (ans == base) cout<< -1;
    else
    cout<< ans <<endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}