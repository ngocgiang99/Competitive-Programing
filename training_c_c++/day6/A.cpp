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

int n, m, q;
int p[MAXN];
char a[MAXN], b[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> a + 1; n = strlen(a+1);
    int k = 0;
    FORE(i,2,n) {
        while(k > 0 && a[k+1] != a[i]) k = p[k];
        if (a[k+1] == a[i]) ++k;
        p[i] = k;
    }

    cin>> q;
    while(q--) {
        cin>> b + 1; m = strlen(b+1);
        int k = 0;
        int ans = 0;
        FORE(i,1,m) {
            while(k > 0 && a[k+1] != b[i]) k = p[k];
            if (a[k+1] == b[i])
                ++k;
            if (k == n) ++ans;
        }
        cout<< ans <<endl;
    }



    return 0;
}