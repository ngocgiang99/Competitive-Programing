#include <bits/stdc++.h>
#define FORE(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define FOR(i, a, b) for(int i = a; i < b; i++)
const int MAXN = 1e5 * 5;
const int INF = 1e9 + 7;
 
using namespace std;
char ch;
int a,ans[15005],m,hh;
priority_queue <int> h;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("io.inp", "r", stdin);
    freopen("io.out", "w", stdout);
    #endif 
    while (cin>>ch)
    {
        if (ch=='+')
        {
            cin>>a;
            //cout<<a<<endl;
            if (h.size()<15000) h.push(a);
        }
        else
        if (h.size()>0)
        {
            hh=h.top();
            //cout<<hh<<endl;
            h.pop();
            while (h.size()>0 && h.top()==hh) h.pop();
        }
        //cout<<ch<<endl;
    }
    //cout<<h.size()<<endl;
    hh = -1;
    while (h.size()>0)
    {
        if (h.top()!=hh) ans[++m]=h.top();
        hh=h.top();
        h.pop();
    }
    cout<<m<<endl;
    FORE(i,1,m) cout<<ans[i]<<' ';
    return 0;
}