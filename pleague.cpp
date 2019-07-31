#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5*2;

int n;
int s[maxn],dd[maxn],ss[maxn],a[maxn];

void rankmax(int i) 
{
    for(int j = 1; j <= 2*n; ++j)
        {
            ss[j]=s[j];
            dd[j]=0;
        }
        ss[i]=ss[i]+3;
        dd[i]=1;
        dd[a[i]]=1;
        

        for(int j = 1; j <= 2*n; ++j)
        if (i != j && dd[j] == 0 && ss[j]+3 <= ss[i]) 
        {
            ss[j]+=3;
            dd[j]=1;
            dd[a[j]]=1;
        }
        else
        if (i != j && dd[j] == 0 && ss[j] > ss[i])
        {
            ss[j]+=3;
            dd[j];
            dd[a[j]]=1;
        }
        else
        {
            ss[j]+=1;
            ss[a[j]]+=1;
            dd[j]=1;
            dd[a[j]]=1;
        }
        int rank = 0;
        for(int j = 1; j <= 2*n; ++j)
        if (ss[j] > ss[i]) ++rank;
        
        cout<< rank+1 <<' ';
}

void rankmin(int i) 
{
    for(int j = 1; j <= 2*n; ++j)
        {
            ss[j]=s[j];
            dd[j]=0;
        }
        ss[a[i]]=ss[a[i]]+3;
        dd[i]=1;
        dd[a[i]]=1;
        

        for(int j = 1; j <= 2*n; ++j)
        if (i != j && dd[j] == 0 && ss[j] > ss[i]) continue;
        else
        if (i != j && dd[j] == 0 && ss[j] + 1 > ss[i] && ss[a[j]] + 1 > ss[i])
        {
            if (i == 2) cout<< j <<' '<< ss[j] <<' '<< ss[a[j]] <<endl;
            ss[j] += 1;
            ss[a[j]] + 1;
            dd[j] = 1;
            dd[a[j]] = 1;
        }
        else
        if (i != j && dd[j] == 0 && ss[j]+3 > ss[i]) 
        {
            ss[j]+=3;
            dd[j]=1;
            dd[a[j]]=1;
        }
        int rank = 0;
        for(int j = 1; j <= 2*n; ++j)
        if (ss[j] > ss[i]) ++rank;
        
        cout<< rank+1 <<endl; 
}

int main() {
    cin>>n;
    for(int i = 1; i <= 2*n; ++i) cin>> s[i];

    for(int i = 1; i <= n; ++i) 
    {
        int x,y;
        cin>>x>>y;
        a[x]=y;
        a[y]=x;
    }

    for(int i = 1; i <= 2*n; ++i) 
    {
        rankmax(i);
        rankmin(i);
    }
}