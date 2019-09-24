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



const int MAXN = 1e5 + 5;
const int base = 1e9 + 7;
const int N = 5000;

int n;
int a[MAXN];
long long sum[MAXN];

long long calSum(int l, int r) {
    return sum[r] - sum[l-1];
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> n;
    FORE(i,1,n) cin>> a[i];
    sort(a+1, a+n+1);
    FORE(i,1,n) sum[i] = sum[i-1] + a[i];

    long long ans = sum[n];
    FORE(i,1,n) {
        ans = ans + 1ll*(i-1)*a[i] - calSum(1, i-1) + calSum(i+1, n) - 1ll*(n-i)*a[i];
        //cout<< 1ll*(i-1)*a[i] <<' '<< calSum(1, i-1) <<' '<< calSum(i+1, n) <<' '<< 1ll*(n-i)*a[i] << endl;
        //cout<< i <<' '<< ans <<endl;
    }

    long long abc = gcd(ans, n);
    ans /= abc;
    n /= abc;

    cout<< ans <<' '<< n << "\n";

    return 0;
}