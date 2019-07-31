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



const int MAXN = 1e5 * 3 + 7;
const int base = 1e9 + 7;
const int N = 5000;

int n, m, pos;
int s[MAXN], f[2][MAXN], M[MAXN];
int bit[2][MAXN];
ll ans;


void upd(int i, int x, int val) {
    x = 3*n - x + 1;

    while(x <= 3*n) {
        bit[i][x] += val;
        x += x&(-x);
    }
}

int get(int i, int x) {
    x = 3*n - x + 1;

    int res = 0;
    while(x) {
        res += bit[i][x];
        x -= x&(-x);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("new.inp", "r", stdin);
    //freopen("new.out", "w", stdout);
    #endif
    cin>> n >> m;

    int pp = 0;
    int Last = 0;
    int First = 0;
    FORE(i,1,n) {
        int x;
        cin>> x;
        if (x == m) pos = i;

        s[i] = s[i-1];
        if (x < m) ++s[i];

        M[i] = M[i-1];
        if (x == m) ++M[i];

        if (x == m && First == 0) First = i;
        if (x == m) Last = i;
    }

    FORE(i,1,First) {
        //++f[i%2][i - 2*s[i-1] - 2*M[i-1] + 2*n];

        upd(i%2, i - 2*s[i-1] - 2*M[i-1] + 2*n, 1);
        //cout<< i%2 <<' '<< i - 2*s[i-1] <<endl;
    }

    FORE(i,First,n) {
        if (i != First && i <= Last) upd(i%2, i - 2*s[i-1] - 2*M[i-1] + 2*n, 1);
            //++f[i%2][i - 2*s[i-1] - 2*M[i-1] + n];
        //ans += f[i%2][i - 2*s[i] - 2*M[i] + 2 + 2*n];
        ans += get(i%2, i - 2*s[i] - 2*M[i] + 2 + 2*n);

        //cout<< i <<' '<< i%2 <<' '<< i - 2*s[i] <<endl;
        //ans += f[1 - i%2][i - 2*s[i] - 2*M[i] + 1 + 2*n];
        ans += get(1 - i%2, i - 2*s[i] - 2*M[i] + 1 + 2*n);

        //cout<< i <<' '<< 1 - i%2 <<' '<< i - 2*s[i] - 1 <<endl;
        cout<< i <<' '<< ans <<' '<< get(i%2, i - 2*s[i] - 2*M[i] + 2 + 2*n) <<' '<< get(1 - i%2, i - 2*s[i] - 2*M[i] + 1 + 2*n) <<endl;

    }

    cout<< ans <<endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
