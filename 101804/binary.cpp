#include <bits/stdc++.h>
#define for1(i,n) for (int i=1; i<=(n); ++i)
#define fore(i,a,b) for (int i=(a); i<=(b); ++i)
const int mn=150;
using namespace std;

int n,k,x;
string c[mn][mn],t[mn][mn];
bool cmp(string a, string b)
{
    while (a.length() < b.length()) a="0"+a;
    while (b.length() < a.length()) b="0"+b;
    return (a>b);
}
string add(string a, string b)
{
    string res="";
    while (a.length() < b.length()) a="0"+a;
    while (b.length() < a.length()) b="0"+b;
    int cr=0;
    for (int i=a.length()-1; i>=0; --i)
    {
        int tmp=a[i]-48+b[i]-48+cr;
        cr=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if (cr>0) res="1"+res;
    return res;
}
string sub(string a, string b)
{
    string res="";
    while (a.length() < b.length()) a="0"+a;
    while (b.length() < a.length()) b="0"+b;
    bool neg=false;
    if (a<b) {swap(a,b); neg=true;}
    int br=0;
    for (int i=a.length()-1; i>=0; --i)
    {
        int tmp=a[i]-b[i]-br;
        if (tmp<0) {tmp+=10; br=1;}
        else br=0;
        res=(char)(tmp+48)+res;
    }
    while (res.length()>1 && res[0]=='0') res.erase(0,1);
    if (neg) res="-"+res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("binary.inp","r",stdin);
    freopen("binary.out","w",stdout);
    cin>>n>>k;
    c[0][0]="1";
    for1(i,n)
       fore(j,0,n) c[i][j]=add(c[i-1][j-1],c[i-1][j]);

    string tmp="0";
    fore(i,0,k) tmp=add(tmp,c[n][i]);
    cout<<tmp<<"\n";
    fore(i,0,n-1)
    {
        t[i][0]="1";
        fore(j,1,k)
           if (j<=i) t[i][j]=add(t[i][j-1],c[i][j]);
           else t[i][j]=t[i][j-1];
    }
    //cout<< "WTF" <<endl;
    int v;
    //cin>> v;
    //cout<< n <<' '<< k <<endl;
    //cout<< v <<endl;
    while (cin>>v)
    {
        if (v==1)
        {
            string res="1";
            int dem=0;
            for1(i,n)
            {
                cin>>x;
                if (x==1)
                {
                  //fore(j,0,k-dem) if (j<=n-i) res=add(res,c[n-i][j]);
                  res=add(res,t[n-i][k-dem]);
                  ///cout<< i <<' '<< res <<endl;
                  ++dem;
                }
            }
            cout<<res<<"\n";
        }
        if (v==2)
        {
            string vt;
            cin>>vt;
            int dem=0;
            for1(i,n)
            {
                //string tmp="0";
                //fore(j,0,k-dem) if (j<=n-i) tmp=add(tmp,c[n-i][j]);
                string tmp=t[n-i][k-dem];
                if (cmp(vt,tmp)) {cout<<1<<" "; vt=sub(vt,tmp); ++dem;}
                else cout<<0<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
