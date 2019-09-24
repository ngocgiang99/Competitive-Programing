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
long long h;
int p[MAXN], d[MAXN], ok[MAXN];

void input() {
    cin>> n >> h;
    //cout<< n <<' '<< h <<endl;
    FORE(i,1,n) cin>> p[i] >> d[i];
}

void process() {
    FORE(i,1,n) ok[i] = 1;

   
    int cnt = 0;
    FORE(i,1,n) {
        int mx = 0;
        int mi = 1e9;
        int jmax = 0;
        FORE(j,1,n)
        if (ok[j] && h >= p[j]) {
            if (d[j] > mx) {
                mx = d[j];
                mi = p[j];
                jmax = j;
            }
            else if (d[j] == mx && mi > p[j])
            {
                mi = p[j];
                jmax = j;
            }
        }
        if (jmax == 0) break;
        h = h - mi + mx;
        //cout<< h <<' '<< jmax <<endl;
        ok[jmax] = 0;
        ++cnt;
    }
    if (cnt < n) cout<< "NO" <<endl;
    else cout<< "YES" <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin>> t;
    //cout<< t <<endl;
    while(t--) {
        input();
        process();
    }





    return 0;
}