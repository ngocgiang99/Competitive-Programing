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


int n, q;
double a[MAXN], bit[MAXN];

void upd(int x, double val) {
    while(x <= n) {
        bit[x] += val;
        x += x&(-x);
    }
}

double get(int x) {
    double res = 0.0;
    //cout<< res <<endl;
    while(x) {
        res += bit[x];
        //cout<< res <<endl;
        x -= x&(-x);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("D.inp", "r", stdin);
    freopen("D.ans", "w", stdout);
    #endif

    cin>> n;
    FORE(i,1,n) cin>> a[i];

    FORE(i,1,n) upd(i, a[i]);

    cout<< fixed << setprecision(7);
    cin>> q;
    while(q--) {
        int ans, l, r, u;
        double x;
        cin>> ans;
        if (ans == 1) {
            cin>> u >> x;
            //cout<< x - a[u] <<endl;
            upd(u, x - a[u]);
            a[u] = x;
        }
        else {
            cin>> l >> r;
            double sum = get(r) - get(l-1);
            sum = sum / (r - l + 1);
            cout<< sum <<endl;
        }
        //cout<< bit[1] <<' '<< get(1) <<endl;
    }


    return 0;
}