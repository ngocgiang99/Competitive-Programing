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
int ans;
int a[MAXN], f[MAXN], b[MAXN];

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> n;
    //int n = 1e4;
    //FORE(i,1,n) a[i] = Rand(1,5e4);
    FORE(i,1,n) cin>> a[i];

    FORE(d,1,100) {

        FORE(i,1,n) b[i] = a[i], b[i+n] = a[i] - d;
        FORE(i,1,2*n) f[i] = 0;

        sort(b+1, b+2*n+1);

        int m = 2*n;
        FORE(i,1,n){
            int x = lower_bound(b+1, b+m+1, a[i]) - b;
            int xx = lower_bound(b+1, b+x, a[i] - d) - b;

            f[x] = max(f[x], f[xx] + 1);
            ans = max(ans, f[x]);
        }
    }

    cout<< ans <<endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}