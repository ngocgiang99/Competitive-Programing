#include <bits/stdc++.h>
#define FORE(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define X first
#define Y second
#define ll long long
#define mp make_pair
#define pb push_back
#define endl '\n'

const int MAXN = 1e5 * 5;
const int base = 1e9 + 7;
const int N = 70000;

using namespace std;
int t,dem;
int m,n,k;
int ans;
int f[N],d[N],vt[N];
int it[MAXN],dit[MAXN],le[MAXN],ri[MAXN],leaf[MAXN];
int index(int u,int v)
{
    if (u == 0) return 0;
    if (v == 0) return 0;
    return (u-1)*n + v;
}

int calc(int u1,int v1,int u2,int v2)
{
    if (u1 > u2) swap(u1,u2);
    if (v1 > v2) swap(v1,v2);
    return f[index(u2,v2)] - f[index(u1-1,v2)] - f[index(u2,v1-1)] + f[index(u1-1,v1-1)] ;
}


void build(int x,int l,int r)
{
    le[x] = l; ri[x] = r;
    if (l == r)
    {
        leaf[l] = x;
        return;
    }
    int mid = (l+r)>>1;
    build(2*x,l,mid);
    build(2*x+1,mid+1,r);
}

void update(int u,int value)
{
    int x1 = leaf[u];
    if (dit[x1] < dem) it[x1] = value;
    dit[x1] = dem;
    while (x1/2)
    {
        int x = x1>>1;
        int x2 = x1&1 ? 2*x : 2*x+1;
        if (dit[x2] < dem) it[x] = it[x1];
        else
        {
            it[x] = min(it[x1] , it[x2]);
        }
        dit[x] = dem;
        x1 >>= 1;
    }
}

int get(int x,int l,int r)
{
    if (l > ri[x] || r < le[x]) return n+1;
    if (l <= le[x] && ri[x] <= r && dit[x] == dem) return it[x];
    if (l <= le[x] && ri[x] <= r && le[x] == ri[x]) return n+1;
    int kq1 = get(2*x,l,r);
    int kq2 = get(2*x+1,l,r);
    return min(kq1,kq2);
}

void sub3()
{
    int doi;
    if (m > n ) doi = 1;
    else doi = 0;
    if (doi)
    {
        swap(m,n);
        FORE(j,1,n)
        FORE(i,1,m)
        {
            char ch; int cp = 0;
            cin>>ch;
            if (ch == 'A') cp = 1;
            else cp = -1;
            f[index(i,j)] = f[index(i-1,j)] + f[index(i,j-1)] - f[index(i-1,j-1)] + cp;
        }
    }
    else
        FORE(i,1,m)
        {
            FORE(j,1,n)
            {
                char ch; int cp = 0;
                cin>>ch;
                if (ch == 'A') cp = 1;
                else cp = -1;
                f[index(i,j)] = f[index(i-1,j)] + f[index(i,j-1)] - f[index(i-1,j-1)] + cp;
            }
        }
    int tt = m*n;
    ans = 0;
    FORE(u1,1,m)
    FORE(u2,u1,m)
    {
        ++dem;
        vt[tt] = 0;
        dit[tt] = dem;
        int s = 0;
        FORE(j,1,n)
        {
            s += calc(u1,j,u2,j);
            int i = dit[s+tt] == dem ? vt[s+tt] : n+1;
            ans = max(ans , (u2 - u1 + 1)*(j - i));
            if (dit[s+tt] < dem) vt[s+tt] = j;
            dit[s+tt] = dem;
        }
    }
    cout<<ans<<endl;
}

void sub4()
{
    int doi;
    if (m > n ) doi = 1;
    else doi = 0;
    if (doi)
    {
        swap(m,n);
        FORE(j,1,n)
        FORE(i,1,m)
        {
            char ch; int cp = 0;
            cin>>ch;
            if (ch == 'A') cp = 1;
            else cp = -1;
            f[index(i,j)] = f[index(i-1,j)] + f[index(i,j-1)] - f[index(i-1,j-1)] + cp;
        }
    }
    else
        FORE(i,1,m)
        {
            FORE(j,1,n)
            {
                char ch; int cp = 0;
                cin>>ch;
                if (ch == 'A') cp = 1;
                else cp = -1;
                f[index(i,j)] = f[index(i-1,j)] + f[index(i,j-1)] - f[index(i-1,j-1)] + cp;
            }
        }
    int tt = m*n;
    ans = 0;
    build(1,0,2*m*n);
    FORE(u1,1,m)
    FORE(u2,u1,m)
    {
        ++dem;
        update(m*n,0);
        int s = 0;
        FORE(j,1,n)
        {
            s += calc(u1,j,u2,j);
            int i = get(1,s-k+tt,s+k+tt);
            ans = max(ans , (u2 - u1 + 1)*(j - i));
            update(s+tt,j);
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("abrec.inp", "r", stdin);
    freopen("abrec.out", "w", stdout);
    #endif
    cin>>t;
    while (t)
    {
        --t;
        cin>>m>>n>>k;
        if (k == 0)
        {
            sub3();
            continue;
        }
        //sub4();
        //continue;
        if (m*n > 2000)
        {
            ans = 0;
            sub4();
            continue;
        }
        FORE(i,1,m)
        {
            FORE(j,1,n)
            {
                char ch; int cp = 0;
                cin>>ch;
                if (ch == 'A') cp = 1;
                else cp = -1;
                f[index(i,j)] = f[index(i-1,j)] + f[index(i,j-1)] - f[index(i-1,j-1)] + cp;
            }
        }
        ans = 0;
        //if (t == 0) cout<<f[index(1,2)]<<' '<<calc(1,1,1,2)<<endl;
        FORE(u1,1,m)
        FORE(u2,u1,m)
        if ((u2-u1+1)*n > ans)
        {
            FORE(v1,1,n)
            FORD(v2,n,v1)
            if ((u2-u1+1) * (v2-v1+1) > ans && abs(calc(u1,v1,u2,v2)) <= k)
            {
                ans = (u2-u1+1) * (v2-v1+1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
