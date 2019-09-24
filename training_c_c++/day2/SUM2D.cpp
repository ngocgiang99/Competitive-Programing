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



const int MAXN = 2e6 + 5;
const int base = 1e9 + 7;
const int N = 5000;

int m, n, q;
int a[MAXN];
long long f[MAXN];

int id(int i, int j) {
    return i * n + j;
}

long long sum(int x1, int y1, int x2, int y2) {
    return f[id(x2, y2)] - f[id(x1-1, y2)] - f[id(x2, y1-1)] + f[id(x1-1, y1-1)];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    //freopen("SUM2D.inp", "r", stdin);
    //freopen("SUM2D.out", "w", stdout);
    read(m); read(n);
    FORE(i,1,m)
    FORE(j,1,n) read(a[id(i, j)]);
    
    FORE(i,1,m)
    FORE(j,1,n) {
        f[id(i,j)] = f[id(i-1, j)] + f[id(i, j-1)] - f[id(i-1, j-1)] + a[id(i, j)];
    }   

    read(q);
    while(q--) {
        int x1, y1, x2, y2;
        read(x1); read(y1); read(x2); read(y2);
        cout<< sum(x1, y1, x2, y2) <<endl;
    }


    return 0;
}