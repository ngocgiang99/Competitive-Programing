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


int n, k;
int f[MAXN][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("BTK.inp", "r", stdin);
    freopen("BTK.out", "w", stdout);

    cin>> n >> k;
    if (k == 1) {
        cout<< 1 <<endl;
        return 0;
    }
    int sum = 1;
    f[1][0] = f[1][1] = 1;
    FORE(i,2,n) {
        f[i][0] = (f[i-1][1] + f[i-1][0]) % base;
        if (i < k) {
            f[i][1] =  (f[i-1][1] + f[i-1][0]) % base;
            sum = (sum + f[i][0]) % base;
        }
        else {
            sum = (sum - f[i-k][0] + base) % base;
            f[i][1] = sum;
            sum = (sum + f[i][0]) % base;
        }
        //cout<< i <<' '<< f[i][0] <<' '<< f[i][1] <<endl;
    }

    cout<< (f[n][1] + f[n][0]) % base <<endl;


    return 0;
}