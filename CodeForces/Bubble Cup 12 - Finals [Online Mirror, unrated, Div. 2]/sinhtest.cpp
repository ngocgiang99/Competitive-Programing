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

int a[N][N], c[N][N], bar[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("input.inp", "r", stdin);
    freopen("input.inp", "w", stdout);
    #endif
    srand(time(NULL));
    int n = 3 + (rand() % 5);
    cout<< n <<endl;
    FORE(i,1,n) {
        FORE(j,1,n) a[i][j] = c[i][j] = rand()%2;
        //cout<<endl;
    }
    FORE(i,1,n) {
        bar[i] = rand()%2;
    }

    FORE(i,1,n) {
        int x = rand()%2;
        if (x)
        FORE(j,1,n) a[i][j] = a[i][j] ^ bar[j];
    }

    FORE(j,1,n) {
        int x = rand()%2;
        if (x)
        FORE(i,1,n) a[i][j] = a[i][j] ^ bar[i];
    }

    FORE(i,1,n) {
        FORE(j,1,n) cout<< a[i][j];
        cout<<endl;
    }

    FORE(i,1,n) {
        FORE(j,1,n) cout<< c[i][j];
        cout<<endl;
    }

    FORE(i,1,n) {
        cout<< bar[i];
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}