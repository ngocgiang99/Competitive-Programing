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
const int N = 5005;

int n;
int a[N];
long long sum[N];

long long calSum(int l, int r) {
    return sum[r] - sum[l-1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> n;
    FORE(i,1,n) cin>> a[i];
    FORE(i,1,n) sum[i] = sum[i-1] + a[i];
    //cout<< sum[n] <<endl;

    long long ans = -1e15;
    FORE(i,1,n+1) {
        long long sum1 = -1e15, sum2 = -1e15;
        FORE(j,0,i-1) 
        if (calSum(1, j) - calSum(j+1, i-1) > sum1) sum1 = calSum(1, j) - calSum(j+1, i-1);
        FORE(j,i-1, n) 
        if (calSum(i, j) - calSum(j+1, n) > sum2) sum2 = calSum(i, j) - calSum(j+1, n);

        ans = max(ans, sum1 + sum2);
    }
    cout<< ans <<endl;

    return 0;
}