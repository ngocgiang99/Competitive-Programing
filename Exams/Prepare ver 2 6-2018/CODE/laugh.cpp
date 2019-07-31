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
const int inf = 1e9 + 7;
const int N = 5000;

using namespace std;
struct trie
{
    int t[5];
}a[MAXN];
int n,m,f[MAXN],li,cnt,ans,d[MAXN];
char c[MAXN];
string s;

int h(char ch)
{
    if (ch == 'a') return 1;
    if (ch == 'b') return 2;
    if (ch == 'c') return 3;
    if (ch == 'h') return 4;
}

void up(int x,int i)
{
    if(i > li)
    {
        d[x] = 1;
        return ;
    }
    int k = h(s[i]);
    if (a[x].t[k]) up(a[x].t[k],i+1);
    else
    {
        a[x].t[k] = ++cnt;
        up(a[x].t[k],i+1);
    }
}

int ok(int x,int i,int r)
{
    //cout<<x<<' '<<i<<' '<<r<<endl;
    if (i == r+1) return d[x];
    int k = h(c[i]);
    if (a[x].t[k]) return ok(a[x].t[k],i+1,r);
    else
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("laugh.inp", "r", stdin);
    freopen("laugh.out", "w", stdout);
    #endif //GIANGPRO
    cin>>m;
    cin>>c+1; n = strlen(c+1);
    //cnt = 1;
    FORE(i,1,m)
    {
        cin>>s; li = s.size() - 1;
        up(0,0);
    }
    //cout<<ok(1,19,22)<<endl;
    FORE(i,1,n)
    {
        int jx = max(i-30,0);
        FORE(j,jx,i-1)
        if (ok(0,j+1,i)) f[i] = max(f[i],f[j] + i-j);
        ans = max(ans , f[i]);
        //cout<<i<<' '<<f[i]<<endl;
    }
    cout<<ans;
    return 0;
}
