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



const int MAXN = 1e6 + 5;
const int base = 1e9 + 7;
const int N = 5000;

typedef pair<int, int> ii;

int n;
long long res;
int a[MAXN], l[MAXN], r[MAXN];
ii b[MAXN];

int cmp(ii A, ii B) {
    if (A.fi != B.fi) return A.fi > B.fi;
    else return A.se < B.se;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> n;
    FORE(i,1,n) {
        cin>> a[i];
        b[i].fi = a[i];
        b[i].se = i;
        l[i] = i-1;
        r[i] = i+1;
    }

    sort(b+1, b+n+1, cmp);

    FORE(x,1,n) {
        int i = b[x].se;
        long long tmp = a[i];
        if (l[i] > 0) {
            tmp += a[l[i]];
            r[l[i]] = r[i];
        }
        if (r[i] < n+1) {
            tmp += a[r[i]];
            l[r[i]] = l[i];
        }
        //cout<< tmp <<endl;
        res += tmp;
    }

    cout << res <<endl;
    return 0;
}