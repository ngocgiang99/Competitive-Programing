#include<bits/stdc++.h>
#define FORE(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define ll long long
#define endl "\n"

const int MAXN = 1e5 * 5;
//const int base  = 1e9 + 7;
const int N = 5000;
const double pi = acos(-1.0);

using namespace std;
typedef pair<ll,ll> ii;
ii l,m,r;
int n;
ll d[MAXN],base;

ll nhan(ll a,ll b)
{
    ll ans = 0;
    ll x = a;
    while (b)
    {
        if (b&1) ans = (ans + x)%base;
        x = (x<<1)%base;
        b >>=1;
    }
    return ans;
}

ll mu(ll x,ll y)
{
    if(y == 0) return 0;
    ll ans = 1;
    ll a = x;
    while (y)
    {
        if (y&1) ans = nhan(ans,a);
        a = nhan(a,a);
        y >>= 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("ps2.inp", "r", stdin);
    freopen("ps2.out", "w", stdout);
    #endif
    cin>>n>>base;
    FORE(i,1,n) cin>>d[i];
    l.x = 0; l.y = 1;
    m.x = 1; m.y = 1;
    r.x = 1; r.y = 0;
    FORE(i,1,n)
    if (i&1)
    {
        l = m;
        l.x = (l.x + nhan(r.x,d[i]-1))%base;
        l.y = (l.y + nhan(r.y,d[i]-1))%base;
        m.x = (l.x + r.x)%base;
        m.y = (l.y + r.y)%base;
        //cout<<m.x<<' '<<m.y<<endl;
    }
    else
    {
        r = m;
        r.x = (r.x + nhan(l.x,d[i]-1))%base;
        r.y = (r.y + nhan(l.y,d[i]-1))%base;
        m.x = (l.x + r.x)%base;
        m.y = (l.y + r.y)%base;
        //cout<<m.x<<' '<<m.y<<endl;
    }
    cout<<m.x<<' '<<m.y<<endl;
    return 0;
}
