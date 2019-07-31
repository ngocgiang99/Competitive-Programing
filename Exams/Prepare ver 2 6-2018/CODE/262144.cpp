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

int n,ans;
int f[262150][60],a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("262144.inp", "r", stdin);
    freopen("262144.out", "w", stdout);
    #endif //GIANGPRO
    cin>>n;
    FORE(i,1,n)
    cin>>a[i];
    FORE(i,1,n)
    f[i][a[i]] = i;
    FORE(x,1,58)
    FORE(i,1,n)
    if (f[i][x] && f[f[i][x]+1][x]) f[i][x+1] = f[f[i][x]+1][x];
    int ok = 0;
    FORD(x,58,1)
    {
        FORE(i,1,n)
        if (f[i][x])
        {
            ans = x;
            ok = 1;
            break;
        }
        if (ok) break;
    }
    cout<<ans;
    return 0;
}
