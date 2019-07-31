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

int n, k, r, p;
int m;
long long ans, res;
int x[10], y[10], pos[10], vis[10];
long long sum[502][502];


ll getsum(int x1, int y1, int x2, int y2) {
    return sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
}

void getsquare(int &x1, int &y1, int &x2, int &y2, int x3, int y3, int x4, int y4) {
    x1 = max(x1 , x3);
    x2 = min(x2 , x4);
    y1 = max(y1 , y3);
    y2 = min(y2 , y4);
}

void upd() {
    int x1 = 1, x2 = n;
    int y1 = 1, y2 = n;

    long long cp = 0;
    long long dau = -1;
    if (m&1) dau *= -1;

    FORE(i,1,m) {
        int j = pos[i];
        getsquare(x1, y1, x2, y2, x[j], y[j], x[j]+r-1, y[j]+r-1);
        if (x1 > x2) return;
        if (y1 > y2) return;

        //res += getsum(x1, y1, x2, y2);
    }
    cp = getsum(x1, y1, x2, y2);

    //cout<< m <<' ';
    //FORE(i,1,m)
    //cout<< pos[i] <<' '; cout<<endl;
    //cout<< res <<endl;

    res += dau*cp;
    //cout<< res <<' '<< ans <<' '<< "ANS" <<endl;
}

void duyet(int i) {
    FORE(j,pos[i-1]+1,p)
    if (!vis[j]) {
        vis[j] = 1;
        pos[i] = j;
        if(i < m) duyet(i+1);
        else upd();
        vis[j] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("bonus.inp", "r", stdin);
    freopen("bonus.out", "w", stdout);
    #endif
    read(n);
    read(k);
    read(r);
    read(p);

    FORE(i,1,n)
    FORE(j,1,n) {
        int x;
        read(x);
        sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + x;
    }

    while(k--) {

        FORE(i,1,p) read(x[i]), read(y[i]);

        res = 0;
        FORE(i,1,p) {
            m = i;
            duyet(1);
        }

        ans = max(ans, res);
    }

    cout<< ans <<endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
