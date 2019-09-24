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
int a[N];
long long f[500][500], g[500][500];
char ope[N];


void prepare(string s) {
    n = 0;
    s += "a";
    int x = 0;
    FORE(i,0,s.length()-1)
    if (isdigit(s[i])) {
        x = x*10 + (s[i] - '0');
    }
    else {
        //cout<< s[i] <<endl;
        a[++n] = x;
        ope[n] = s[i];
        x = 0;
    }
    //FORE(i,1,n)
    //cout<< a[i] <<' '<< ope[i] <<endl;

    FORE(i,1,n)
    FORE(j,1,n) f[i][j] = g[i][j] = -1;
}

long long exe(long long x, long long y, char ope) {
    if (ope == '+') return x + y;
    if (ope == '*') return x * y;
} 

long long calcMax(int l, int r) {
    //cout<< l <<' '<< r <<' '<< f[l][r] <<endl;
    if (f[l][r] != -1) return f[l][r];
    if (l == r) return a[l];
    long long res = -1e15;
    FORE(i,l,r-1)
    res = max(res, exe(calcMax(l, i), calcMax(i+1, r), ope[i]));

    //cout<< l <<' '<< r <<' '<< res <<endl;
    return f[l][r] = res;
}

long long calcMin(int l, int r) {
    //cout<< l <<' '<< r <<' '<< f[l][r] <<endl;
    if (g[l][r] != -1) return g[l][r];
    if (l == r) return a[l];
    long long res = 1e15;
    FORE(i,l,r-1)
    res = min(res, exe(calcMin(l, i), calcMin(i+1, r), ope[i]));

    //cout<< l <<' '<< r <<' '<< res <<endl;
    return g[l][r] = res;
}

void sub123() {
    //cout<< "abc" <<endl;
    cout<< calcMax(1, n) <<' '<< calcMin(1, n) <<endl;
}

void sub4() {

}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("exp.inp", "r", stdin);
    freopen("exp.out", "w", stdout);

    int test;
    cin>> test;
    while(test--) {
        string s;
        cin>> s;
        prepare(s);
        if (n <= 999) sub123();
        else sub4();
    }



    return 0;
}