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
const int N = 50;

int n;
int a[MAXN], cl[N], bit[MAXN];
vector<int> v[N];
long long dp[1050006];
long long c[N][N];


int getBit(int x, int i) {
    return (x >> (i-1)) & 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    // freopen("input.inp", "r", stdin);
    // freopen("output.out", "w", stdout);
    #endif
    cin>> n;
    FORE(i,1,n) {
        cin>> a[i];
        v[a[i]].pb(i);
    }

    FORE(i,1,20)
    FORE(j,1,20) {
        if (i == j || v[i].size() == 0 || v[j].size() == 0) {
            continue;
        }
        int pos2 = 0;
        for (int pos1 = 0; pos1 < v[i].size(); ++pos1) {
            while(true) {
                if (pos2 == v[j].size() || v[j][pos2] > v[i][pos1]) {
                    break;
                }
                ++pos2;
            }
            // cout<< i <<' '<< j <<' '<< pos2 <<endl;
            c[i][j] += pos2;
        }
        // cout<< i <<' '<< j <<' '<< c[i][j] <<endl;
    }

    int mxMask = (1 << 20) - 1;
    
    FORE(x, 0, mxMask) {
        dp[x] = 1e15;
    }
    
    dp[0] = 0;

    FORE(x, 0, mxMask) 
    if (dp[x] != 1e15) {
        FORE(i, 1, 20)
        if (getBit(x, i) == 0) {
            long long sum = 0;
            FORE(j, 1, 20)
            if (getBit(x, j)) sum += c[i][j];
            int nX = x | (1 << (i-1));
            dp[nX] = min(dp[nX], dp[x] + sum);
        } 
    }

    cout<< dp[mxMask - 1] <<endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}