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
const int N = 300;

int m = 50, n = 50, id;
int c[N];
char a[N][N], d[N];

void process() {
    int vd = 0;
    while(true) {
        FORE(i,1,m)
        FORE(j,1,n)
        if (a[i][j] == d[id]) {
            FORE(t,1,4)
            if (t != id) {
                if (c[t]) {
                    a[i][j+1] = d[t];
                    a[i+1][j] = d[t];
                    a[i+1][j+1] = d[t];
                    vd = t;
                }
            }
            --c[id];
            if (c[id] == 0)  {
                --c[vd];
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("new.inp", "r", stdin);
    //freopen("new.out", "w", stdout);
    #endif
    cin>> c[1] >> c[2] >> c[3] >> c[4];
    d[1] = 'A'; d[2] = 'B'; d[3] = 'C'; d[4] = 'D';
    int s = c[1] + c[2] + c[3] + c[4];

    int x = base;
    FORE(i,1,4)
    if (c[i] < x) {
        x = c[i];
        id = i;
    }


    FORE(i,1,m)
    FORE(j,1,n) a[i][j] = d[id];

    --c[id];
    //cout<< id <<' '<< c[id] <<' '<< s <<endl;

    if (c[id]) process();

    int ti = 1;
    FORD(i,m,1)
    FORE(j,1,n) {
        FORE(t,1,4) {
            if (c[t] && a[i][j-1] != d[t] && a[i+1][j] != d[t]) {
                a[i][j] = d[t];
                --c[t];
                //cout<< i <<' '<< j <<' '<< c[1] <<' '<< c[2] <<' '<< c[3] <<' '<< c[4] <<' '<< endl;
                break;
            }
        }

    }

    cout<< m << ' '<< n <<endl;
    FORE(i,1,m) {
        FORE(j,1,n) cout<< a[i][j];
        cout<<endl;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
