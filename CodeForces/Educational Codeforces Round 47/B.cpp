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
const int N = 5000;

int n;
char a[MAXN], b[MAXN];

void write(int l, int r, char c) {
    FORE(i, l, r)
    a[i] = c;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("new.inp", "r", stdin);
    //freopen("new.out", "w", stdout);
    #endif
    cin>> a+1; n = strlen(a+1);

    int cnt = 0;
    int ok2 = 0;
    FORE(i,1,n)
    if (a[i] == '1') {
        //cout<< i <<' '<< ok2 <<' '<< cnt <<endl;
        if (ok2) {
            a[i-cnt] = '1';
            //cout<< i <<endl;
        }
        else {
            FORE(j,1,cnt)
            a[j+i-cnt-1] = b[j];
            cnt = 0;
        }
    }
    else {
        b[++cnt] = a[i];
        if (a[i] == '2') ok2 = 1;
    }
    FORE(i,1,cnt)
    a[i+n-cnt] = b[i];

    cnt = 0;
    FORD(i, n, 1)
    if (a[i] == '0') ++cnt;
    else
    if (a[i] == '1') {
        if (cnt) a[i+cnt] = '1';
    }
    else {
        write(i+1, i+cnt, '0');
        cnt = 0;
    }
    write(1, cnt, '0');

    FORE(i,1,n)
    cout<< a[i];
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
