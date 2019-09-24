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

int n, m;
int cnt;
int g[MAXN];
pair<int, int> e[MAXN];

bool gcd(int a, int b) {
    if (b == 0) return a == 1;
    else return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("new.inp", "r", stdin);
    //freopen("new.out", "w", stdout);
    #endif
    cin>> n >> m;
    if (m < n-1) {
        cout<< "Impossible";
        return 0;
    }

    FORE(i,2,n) {
        e[++cnt] = mp(1, i);
        --m;
    }
    //cout<< m <<endl;

    FORE(i,2,n)
    for(int j = 2*i; ; j += i) {
        int l = j - i + 1;
        int r = min(j-1, n);
        //cout<< i <<' '<< l <<' '<< r <<endl;
        FORE(k,l, r)
        if (m && gcd(k, i)) {
            e[++cnt] = mp(i, k);
            //cout<< m <<' '<< i <<' '<< k <<endl;
            --m;
        }
        if (r == n) break;
        if (!m) break;
    }

    //cout<< m <<endl;

    if (m) cout<< "Impossible";
    else {
        cout<< "Possible" <<endl;

        FORE(i,1,cnt)
        cout<< e[i].fi <<' '<< e[i].se <<endl;
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
