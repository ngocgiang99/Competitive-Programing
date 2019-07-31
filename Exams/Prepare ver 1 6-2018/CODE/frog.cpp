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
const int N = 1003;

int m, n, k;
int a[N][N], trace[N][N], id[N];
long long f[N][N];
deque<long long> dq;

void init() {
    cin>> m >> n >> k;
    FORE(i,1,m)
    FORE(j,1,n) cin>> a[i][j];
}

void process() {
    FORE(i,1,n) f[1][i] = a[1][i];

    FORE(i,2,m) {
        while(dq.size()) dq.pop_back();
        FORE(j,1,min(n,k+1)) {
            while(dq.size() && f[i-1][j] >= f[i-1][dq.back()]) dq.pop_back();
            dq.push_back(j);
        }

        FORE(j,1,n){
            while(dq.size() && j - dq.front() > k) dq.pop_front();

            //int jj = dq.front();
            f[i][j] = f[i-1][dq.front()] + a[i][j];
            trace[i][j] = dq.front();

            if (j + k + 1 <= n) { 
                while(dq.size() && f[i-1][j + k + 1] >= f[i-1][dq.back()]) dq.pop_back();
                dq.push_back(j+k+1);
            }
        }
    }

    long long ans = 0;
    int pos;
    FORE(j,1,n)
    if (f[m][j] > ans) {
        ans = f[m][j];
        pos = j;
    }

    cout<< ans <<endl;
    FORD(i,m,1) {
        id[i] = pos;
        pos = trace[i][pos];
    }
    FORE(i,1,m)
    cout<< id[i] <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("frog.inp", "r", stdin);
    freopen("frog.out", "w", stdout);
    #endif
    
    init();
    process();
    

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
