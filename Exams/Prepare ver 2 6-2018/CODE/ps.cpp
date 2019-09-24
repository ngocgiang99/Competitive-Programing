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
const int base  = 1e9 + 7;
const int N = 5000;
const double pi = acos(-1.0);

using namespace std;
typedef pair<int,int> ii;
ii a,m,l,r;

int kt(ii a,ii b)
{
    return 1ll*a.x*b.y < 1ll*a.y*b.x;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("ps.inp", "r", stdin);
    freopen("ps.out", "w", stdout);
    #endif
    while (1)
    {
        cin>>a.x>>a.y;
        if (a.x == a.y == 1) break;
        l.x = 0; l.y = 1;
        m.x = 1; m.y = 1;
        r.x = 1; r.y = 0;
        while (1)
        {
            if (kt(m,a))
            {
                l = m;
                m.x = l.x + r.x;
                m.y = l.y + r.y;
                cout<<'R';
            }
            else
            {
                r = m;
                m.x = l.x + r.x;
                m.y = l.y + r.y;
                cout<<'L';
            }
            if (m == a)
            {
                cout<<endl;
                break;
            }
        }
    }
    return 0;
}
