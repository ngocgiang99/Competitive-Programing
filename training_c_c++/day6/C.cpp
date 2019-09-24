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



const int MAXN = 1e6 * 2 + 7;
const int base = 1e9 + 7;
const int N = 5000;

int n;
long long ans;
char a[MAXN], ch[MAXN];
int f[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> a+1; n = strlen(a+1);
    int m = 2*n;
    ch[0] = ch[m+1] = '#';
    FORE(i,1,m)
    if (i&1) ch[i] = a[i/2+1];
    else ch[i] = '#';
    // FORE(i,1,m)
    // cout<< ch[i];
    // cout<<endl;

    int l = 0, r = 0;
    FORE(i,1,m) {
        if (i >= r) f[i] = 1;
        else {
            int mid = (l + r) >> 1;
            f[i] = min(f[2 * mid - i], r - i + 1);
        }
        // if (i&1)
        // cout<< i <<' '<< f[i] <<endl;
        while(i + f[i] <= m && i - f[i] >= 0 && ch[i + f[i]] == ch[i - f[i]]) ++f[i];
        if (i + f[i] - 1 > r) {
            r = i + f[i] - 1;
            l = i - f[i] + 1;
        }
    } 

    //ans = 2;
    FORE(i,1,m)
    if (f[i] > 1) {
        // cout<< i <<' ' << f[i]/2 <<endl;
        ans = ans + f[i]/2;
    }
    
    cout<< ans <<endl;

    return 0;
}