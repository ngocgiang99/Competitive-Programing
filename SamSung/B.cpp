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



const int MAXN = 1e4 * 5;
const int base = 1e9 + 7;
const int N = 5000;

int n;
int a[MAXN], f[MAXN], g[MAXN], trace[MAXN];

int check(int x) {
    int len = 0;
    int digit[10];
    //cout<< x <<' ';
    while(x) {
        digit[++len] = x%10;
        x /= 10;
    }
    //cout<< len <<endl;
    FORE(i,1,len/2)
    if (digit[i] != digit[len-i+1]) return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> n;
    int mx = 0;
    FORE(i,1,n) {
        cin>> a[i];
        mx = max(mx, a[i]);
    }

    //check(121);
    //return 0;
    FORE(i,1,mx) {
        g[i] = check(i);
        //if (g[i]) cout<< i <<endl;
    }

    FORE(i,1,mx){
        int mx = base;
        int pos = base;
        FOR(j,0,i)
        if (g[i-j]) {
            if (f[j] < mx) {
                mx = f[j];
                pos = j;
            }
        }
        //cout<< i <<' '<< mx <<endl;
        if (mx != base) {
            f[i] = mx + 1;
            trace[i] = pos;
        }
        else f[i] = -1;
    }

    FORE(i,1,n) {
        if (f[a[i]] != -1) {
            cout<< "Case #" << i <<endl;
            int x = a[i];
            int len = 0;
            int ans[10];
            while(x) {
                int y = trace[x];
                ans[++len] = x - y;
                x = y;
            }
            cout<< len <<' ';
            FORE(i,1,len) cout<< ans[i] <<' ';
            cout<<endl;
        }
    }
    return 0;
}