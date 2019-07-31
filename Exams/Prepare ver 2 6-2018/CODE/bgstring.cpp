#include <bits/stdc++.h>
#define FORE(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define X first
#define Y second
#define ll long long
#define mp make_pair
#define pb push_back
#define endl '\n'

const int MAXN = 1e5 * 5;
const int base = 1e9 + 7;
const int N = 205;

using namespace std;

int n;
int pass,le,ri;
int cnt,len;
int dd[N][N],f[N][N],jump[N][30],g[N][N][N],gg[N][N][N];
char a[N],b[N];

int minimize(int l1,int r1,int l2,int r2)
{
    while(l1 <= r1)
    {
        if (a[l1] != a[l2]) return a[l1] < a[l2];
        ++l1;
        ++l2;
    }
    return 1;
}

void get(int l,int r)
{
    //cout<< l + len - 1<<endl;
    FORE(i,1,len)
    b[i] = a[l+i-1];
}

int check(int l,int r)
{
    //cout<< l <<' '<< r <<endl;
    if (l > r) return 1;
    //if (a[l] != b[1] || a[r] != b[len]) return 0;
    if (a[l] != b[1]) return 0;
    if ((r - l + 1)%len) return 0;
    if (dd[l][r] == cnt) return f[l][r];

    int ok = 0;

    g[l][l][1] = 1;
    gg[l][l][1] = cnt;
    FOR(tt,1,len)
    FORE(i,l,r)
    if (g[l][i][tt] && gg[l][i][tt] == cnt)
    {
        int j = jump[i+1][b[tt+1] - 'a'];
        while(j <= r)
        {
            g[l][j][tt+1] = g[l][i][tt] & check(i+1,j-1);
            gg[l][j][tt+1] = cnt;
            j = jump[j+1][b[tt+1] - 'a'];
        }
    }
    if (gg[l][r][len] == cnt)
    ok = g[l][r][len];
    if (ok == 0)
        FORE(j,l,r)
        if (g[l][j][len] && gg[l][j][len] == cnt)
        {
            ok = check(j+1,r);
            if (ok) break;
        }
    dd[l][r] = cnt;
    f[l][r] = ok;
    return ok;
}

void debug()
{
    len = 4;
    cnt = 1;
    b[1] = 'b'; b[2] = 'a'; b[3] = 'b'; b[4] = 'a';
    cout<< check(1,n) <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("bgstring.inp", "r", stdin);
    freopen("bgstring.out", "w", stdout);
    #endif
    cin>>a+1; n = strlen(a+1);
    FORE(i,0,25) jump[n+1][i] = n+1;
    FORD(i,n,1)
    {
        FORE(j,0,25) jump[i][j] = jump[i+1][j];
        jump[i][a[i] - 'a'] = i;
    }
    FORE(i,1,n)
    if (n%i == 0)
    {
        int p = n-i+1;
        FORE(j,1,p)
        {
            len = i;
            get(j,j+i-1);
            ++cnt;
            if (check(1,n))
            {
                if (pass == 0) le = j , ri = j+i-1 , pass = 1;
                else
                {
                    if (minimize(le,ri,j,j+i-1) == 0) le = j , ri = j+i-1;
                }
            }
        }
        if (pass) break;
    }
    FORE(i,le,ri)
    cout<< a[i];
    return 0;
}
