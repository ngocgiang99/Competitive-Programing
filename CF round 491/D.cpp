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


int f[N][3][3];
char a[3][N];
int n;

void maximize(int &a, int b) {
    a = max(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);


    cin>> a[1]+1; 
    cin>> a[2]+1; 
    n = strlen(a[2]+1);
    FORE(i,1,2)
    FORE(j,1,n)
    if (a[i][j] == 'X') a[i][j] = '1';

    //f[1][a[1][1] - '0'][a[2][1] - '0'] = 0;
    FORE(i,2,n) {
        FORE(x3,a[1][i-1] - '0',1)
        FORE(x4,a[2][i-1] - '0',1) {
            if (x3 == 0 && x4 == 0 && a[1][i] =='0') maximize(f[i][1][a[2][i] - '0'], f[i-1][x3][x4] + 1);
            if (x3 == 0 && a[1][i] == '0' && a[2][i] == '0') maximize(f[i][1][1], f[i-1][x3][x4] + 1);
            if (x3 == 0 && x4 == 0 && a[2][i] == '0') maximize(f[i][a[1][i] - '0'][1], f[i-1][x3][x4] + 1);
            if (x4 == 0 && a[1][i] == '0' && a[2][i] == '0') maximize(f[i][1][1], f[i-1][x3][x4] + 1);
        }
            //cout<< i <<' '<< x1 <<' '<< x2 <<' '<< f[i][x1][x2] <<endl;
        FORE(x3,a[1][i-1] - '0',1)
        FORE(x4,a[2][i-1] - '0',1) {
            maximize(f[i][a[1][i] - '0'][a[2][i] - '0'], f[i-1][x3][x4]);
        }
    }

    int ans = 0;
    FORE(x1,0,1)
    FORE(x2,0,1) ans = max(ans, f[n][x1][x2]);

    cout<< ans;
    return 0;
}