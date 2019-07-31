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
const int N = 3005;

int n, ans, k;
int f[N][N];
char a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> a+1; n = strlen(a+1);
    cin>> k;
    FORD(i,n,1)
    FORE(j,i,n)
    if (a[i] == a[j]) f[i][j] = f[i+1][j-1];
    else f[i][j] = f[i+1][j-1] + 1;

    FORE(i,1,n)
    FORE(j,i,n)
    if (f[i][j] <= k) ++ans;

    cout<< ans <<endl;
    return 0;
}