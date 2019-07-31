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
int n;
string f[103][101],ans;

string add(string a,string b)
{
    while (a.size() < b.size()) a = "0" + a;
    while (b.size() < a.size()) b = "0" + b;
    int top = a.size() - 1;
    int s = 0,r = 0;
    string c = a;
    FORD(i,top,0)
    {
        s = r + (a[i] - '0') + (b[i] - '0');
        r = s/10;
        c[i] = (s%10) + '0';
    }
    if (r) c = "1" + c;
    return c;
}

string calc(int i,int c)
{
    if (f[i][c] != "-1") return f[i][c];
    if (i > n)
        if (c == 0) return "1";
        else return "0";
    string cnt = calc(i+1,c+1);
    if (c) cnt = add(cnt , calc(i+1,c-1));
    f[i][c] = cnt;
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("bt1.inp", "r", stdin);
    freopen("bt1.out", "w", stdout);
    #endif //GIANGPRO
    while (cin>>n)
    {
        FORE(i,1,n+1)
        FORE(j,0,n) f[i][j] = "-1";
        ans = calc(1,0);
        if (ans.size() <= 10) cout<<ans;
        else
        {
            FORE(i,0,4) cout<<ans[i];
            cout<<"...";
            FORE(i,ans.size()-5,ans.size()-1) cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}
