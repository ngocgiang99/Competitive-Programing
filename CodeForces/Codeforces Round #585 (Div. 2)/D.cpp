#include <bits/stdc++.h>
using namespace std;
#define FORE(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORIT(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define fi first
#define se second
#define ll long long
#define mp make_pair
#define pb push_back
#define all(a) a.begin(),a.end()
#define sqr(x) (x)*(x)
#define endl '\n'

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
const int N = 500;

int n;
char a[MAXN];

void loss() {
    cout << "Bicarp";
}

void win() {
    cout<< "Monocarp";
}

void process() {
    int cnt = 0;
    FORE(i,1,n)
    if (a[i] == '?') ++cnt;
    if (cnt == 0) {
        int suma = 0;
        int sumb = 0;
        FORE(i,1,n)
        if (i <= n/2) suma += a[i] - '0';
        else sumb += a[i] - '0';
        if (suma == sumb) {
            loss();
        }
        else {
            win();
        }
        return;
    }


    int suma = 0, sumb = 0;
    FORE(i,1,n)
    if (a[i] != '?')
    if (i <= n/2) suma += a[i] - '0';
    else sumb += a[i] - '0';

    int cnta = 0, cntb = 0;
    FORE(i,1,n)
    if (a[i] == '?')
    if (i <= n/2) ++cnta;
    else ++cntb;
    
    if (cnta == cntb && suma == sumb) {
        loss();
        return;
    }
    if (suma == sumb && cnta != cntb) {
        win();
        return;
    }
    
    if (suma < sumb) {
        swap(cnta, cntb);
        swap(suma, sumb);
    }
    suma = suma + ((cnta + 1) / 2) * 9;
    // cout<< suma <<' '<< sumb <<endl;
    int tt = cntb&1;
    int xx = ((cnta + 1) / 2) * 9;
    if (suma < sumb + ((cntb / 2) * 9)) {
        win();
        return;
    }
    // cerr << "ABC" <<endl;
    // cerr << suma <<' '<< sumb <<' '<< ((cntb / 2) * 9) <<' '<< xx <<endl;
    if (suma <= sumb + xx) {
        loss();
        return ;
    }
    win();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    // freopen("input.inp", "r", stdin);
    // freopen("output.out", "w", stdout);
    #endif
    cin>> n;
    cin>> a+1;
    process();


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}