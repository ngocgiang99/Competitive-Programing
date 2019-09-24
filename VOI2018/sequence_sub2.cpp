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
const int P = 10;

int n;
//int ans;
priority_queue<int> h;

int a[N], f[P][2*P + 5], trace[P][2*P + 5];
int ans[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("sequence.inp", "r", stdin);
    freopen("sequence.out", "w", stdout);
    #endif
    cin>> n;
    FORE(i,1,n) cin>> a[i], a[i] -= i;

    FORE(x, 0, 2*P) {
        //x -= 10;
        f[1][x] = base;

        FORE(y,0,x) {
            int yy = y - P;
            if (f[1][x] > abs(a[1] - yy)) {
                f[1][x] = abs(a[1] - yy);
                trace[1][x] = y;
            }
        }
        if (x != 2*P) cout<< f[1][x] <<' ';
        else cout<< f[1][x] <<endl;
    }

    int mi = base;
    int pos;
    FORE(x,0,2*P)
    if (f[1][x] < mi) {
        mi = f[1][x];
        pos = x;
    }
    cout<< pos - P <<endl;

    FORE(i,2,n)
    {
        FORE(x,0,2*P) {
            f[i][x] = base;
            FORE(y,0, x) {
                int yy = y - P;

                if (f[i][x] > f[i-1][y] + abs(a[i] - yy)) {
                    f[i][x] = f[i-1][y] + abs(a[i] - yy);
                    trace[i][x] = y;
                    //if (y == 305)
                    //cout<< i <<' '<< x <<' '<< f[i][x] <<' '<< f[i-1][y] <<' '<< abs(a[i] - yy) <<endl;
                }
            }
        }

        int mi = base;
        int pos;
        FORE(x,0,2*P)
        if (f[i][x] < mi) {
            mi = f[i][x];
            pos = x;
        }

        FORE(x,0,2*P)
        cout<< f[i][x] <<' ';
        cout<<endl;
        cout<< pos - P <<endl;
    }

    mi = base;
    pos = 2*P;
    int i = n;
    while(i) {
        //cout<< i <<' '<< trace[i][pos] - P + i <<endl;
        ans[i] = trace[i][pos] - P + i;
        pos = trace[i][pos];
        --i;
    }

    cout<< f[n][2*P] <<endl;
    FORE(i,1,n)
    cout<< ans[i] <<' ';
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
