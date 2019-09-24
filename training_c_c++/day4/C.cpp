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

int n,k;
long long ans;
pair<int, int> a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> n >> k;
    FORE(i,1,n) cin>> a[i].fi >> a[i].se;

    sort(a+1, a+n+1);

    int rig = n;
    while(a[rig].fi > 0) {
        int cnt = a[rig].se / k;
        ans += 2ll*cnt*a[rig].fi;
        if (a[rig].se % k) {
            int r = k - a[rig].se % k;
            ans += 2ll*a[rig].fi;
            --rig;
            while(a[rig].fi > 0 && r >= a[rig].se) {
                r -= a[rig].se;
                --rig;
            }
            if (a[rig].fi > 0)
            a[rig].se -= r;
        }
        else --rig;
    }

    int lef = 1;
    while(a[lef].fi < 0) {
        int cnt = a[lef].se / k;
        ans -= 2ll*cnt*a[lef].fi;
        if (a[lef].se % k) {
            int r = k - a[lef].se % k;
            ans -= 2ll*a[lef].fi;
            ++lef;
            while(a[lef].fi < 0 && r >= a[lef].se) {
                r -= a[lef].se;
                ++lef;
            }
            if (a[lef].fi < 0)
            a[lef].se -= r;
        }
        else ++lef;
    }

    cout<< ans <<endl;
    return 0;
}