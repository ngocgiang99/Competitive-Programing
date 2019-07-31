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

const int MAXN = 1e5 * 5;
const int base  = 1e9 + 7;
const int N = 5000;
const double pi = acos(-1.0);
const double ep = 1e-6;

int n,k;
int p[10];
ll ans;
vector<int> ve;

void pt(int x)
{
    int cnt = 0;
    while (x)
    {
        int r = x%10;
        ve.pb(-(9-r)*p[cnt]);
        x /= 10;
        ++cnt;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("digits.inp", "r", stdin);
    freopen("digits.out", "w", stdout);
    #endif
    p[0] = 1;
    FORE(i,1,9)
    p[i] = p[i-1]*10;
    ve.pb(0);
    cin>>n>>k;
    FORE(i,1,n)
    {
        int a;
        cin>>a;
        pt(a);
    }
    sort(ve.begin(),ve.end());
    if (k > ve.size()) k = ve.size();
    FOR(i,0,k)
    ans -= 1ll*ve[i];
    cout<<ans;
    return 0;
}
