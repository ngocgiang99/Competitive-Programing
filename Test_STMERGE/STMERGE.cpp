#include <bits/stdc++.h>
using namespace std;
const int mn=1e3+7;
const long long oo=1e15+7;
int q,m,n;
int c[mn][mn];
long long f[mn][mn][2],res;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("STMERGE.inp","r",stdin);
    freopen("STMERGE.out","w",stdout);
    cin>>q;
    for(int k=1;k<=q;k++)
    {  cin>>m>>n;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++) cin>>c[i][j];
        for(int i=1;i<=m;i++) f[i][0][1]=oo;
        for(int i=1;i<=n;i++) f[0][i][0]=oo;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {  f[i][j][0]=min(f[i-1][j][0],f[i-1][j][1]+c[i][j]);
                f[i][j][1]=min(f[i][j-1][0]+c[i][j],f[i][j-1][1]);
            }
        res=min(f[m][n][0],f[m][n][1]);
        cout<<res<<'\n';
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
