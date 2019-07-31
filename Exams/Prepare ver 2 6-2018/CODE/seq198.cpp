#include <bits/stdc++.h>
using namespace std;
#define FORE(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define pb push_back
#define endl '\n'
#define ll long long
#define X first
#define Y second

const int MAXN = 1e5 * 5;
const int base = 1e9 + 7;
const int N = 2001;
const int X = 1024;

int n;
int ans;
int a[N],b[N];
int x[N];
int f[N][X];

void upd()
{
    int cnt = 0;
    FORE(i,1,min(n,10))
    if (x[i] == 1)
    {
        cnt += b[i];
        FORD(j,i-1,1)
        if (x[j])
        {
            if (a[i] - a[j] > 9) break;
            else
            {
                if (a[i] - a[j] == 1) return;
                if (a[i] - a[j] == 8) return;
                if (a[i] - a[j] == 9) return;
            }
        }
    }
    int xx = 0;
    FORE(i,1,min(n,10))
    xx = xx*2 + x[i];
    f[10][xx] = cnt;
    ans = max(ans , cnt);
}

void duyet(int i)
{
    FORE(j,0,1)
    {
        x[i] = j;
        if (i < min(n,10)) duyet(i+1);
        else upd();
    }
}

int get(int x,int i)
{
    return x & (1<<(i-1));
}

int check(int x)
{
    if (x == 1) return 1;
    if (x == 9) return 1;
    if (x == 8) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("seq198.inp" , "r" , stdin);
    freopen("seq198.out" , "w" , stdout);
    cin>>n;
    FORE(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    int n1 = 0;
    a[0] = -1;
    FORE(i,1,n)
    if (a[i] != a[i-1])
    {
        a[++n1] = a[i];
        b[n1] = 1;
    }
    else ++b[n1];
    int m = n;
    n = n1;
    duyet(1);
    if (n <= 10)
    {
        cout<<m - ans<<endl;
        return 0;
    }
    //FORE(i,1,n)
    //cout<<a[i]<<' '<<b[i]<<endl;
    FOR(i,10,n)
    FORE(xx,0,1023)
    {
        int ok = 0;
        int xo = (xx*2)%X;
        f[i+1][xo] = max(f[i+1][xo] , f[i][xx]);
        FORE(j,1,9)
        if (get(xx,j) && check(a[i+1] - a[i-j+1]))
        {
            ok = 1;
            break;
        }
        if (ok) continue;
        xo = (2*xx + 1)%X;
        f[i+1][xo] = max(f[i+1][xo] , f[i][xx] + b[i+1]);
    }
    FORE(i,1,n)
    FORE(x,0,1023)
    ans = max(ans , f[i][x]);
    cout<<m - ans<<endl;
    return 0;
}
