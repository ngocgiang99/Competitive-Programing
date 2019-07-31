#include<bits/stdc++.h>
using namespace std;
#define FORE(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define ll long long
#define endl "\n"
#define NAME "hstr."
#ifndef ONLINE_JUDGE
ifstream fi (NAME"inp");
ofstream fo (NAME"out");
#endif

const int MAXN = 1e5 * 5;
const int base  = 1e9 + 7;
const int N = 3005;
const double pi = acos(-1.0);
const double ep = 1e-6;

int n,k,ans;
char a[N],b[N];
int g[N][N];

int check(int l1,int r1,int l2,int r2)
{
    while (l1 <= r1)
    {
        if (abs(b[l1] - a[l2]) > k) return 0;
        ++l1;
        ++l2;
    }
    return 1;
}

int kt(int l,int r)
{
    if (check(1,l,1,l) && check(l+1,r-1,l+1,r-1) && check(r,n,r,n)) return 1;
    if (check(1,l,1,l) && check(l+1,l+1+(n-r+1)-1,r,n) && check(l+1+(n-r+1),n,l+1,r-1)) return 2;
    if (check(1,(r-1)-(l+1)+1,l+1,r-1) && check((r-1)-(l+1)+2,(r-1)-(l+1)+2+l-1,1,l) && check((r-1)-(l+1)+2+l,n,r,n)) return 3;
    if (check(1,(r-1)-(l+1)+1,l+1,r-1) && check((r-1)-(l+1)+2,(r-1)-(l+1)+2+(n-r+1)-1,r,n) && check((r-1)-(l+1)+2+(n-r+1),n,1,l)) return 4;
    if (check(1,(n-r+1),r,n) && check((n-r+1)+1,(n-r+1)+1+l-1,1,l) && check((n-r+1)+1+l,n,l+1,r-1)) return 5;
    if (check(1,(n-r+1),r,n) && check((n-r+1)+1,(n-r+1)+1+(r-1)-(l+1)+1-1,l+1,r-1) && check((n-r+1)+1+(r-1)-(l+1)+1,n,1,l)) return 6;
}

void sub1()
{
    FORE(i,1,n)
    FORE(j,i+2,n)
    if (kt(i,j))
    {
        //fo<<i<<' '<<j<<' '<<kt(i,j)<<endl;
        ++ans;
    }
    fo<<ans<<endl;
}

int cnt(int x,int y,int z)
{
    int res = 0;
    if (g[1][1] >= x && g[x+1][x+1] >= y && g[x+y+1][x+y+1] >= z) ++res;
    if (g[1][1] >= x && g[x+y+1][x+1] >= z && g[x+1][x+z+1] >= y) ++res;
    if (g[x+1][1] >= y && g[1][y+1] >= x && g[x+y+1][x+y+1] >= z) ++res;
    if (g[x+1][1] >= y && g[x+y+1][y+1] >= z && g[1][y+z+1] >= x) ++res;
    if (g[x+y+1][1] >= z && g[1][z+1] >= x && g[x+1][x+z+1] >= y) ++res;
    if (g[x+y+1][1] >= z && g[x+1][z+1] >= y && g[1][y+z+1] >= x) ++res;
    //fo<<x<<' '<<y<<' '<<z<<' '<<res<<endl;
    return res > 0;
}

void sub23()
{
    FORD(i,n,1)
    FORD(j,n,1)
    if (abs(a[i] - b[j]) <= k)
    g[i][j] = g[i+1][j+1] + 1;
    FORE(i,1,n)
    FOR(j,i+1,n)
    ans += cnt(i,j-i,n-j);
    fo<<ans<<endl;
}

int main()
{
    fi>>k;
    fi>>a+1; n = strlen(a+1);
    fi>>b+1;
    //if (n <= 300) sub1();
    //else sub23();
    sub23();
    return 0;
}
