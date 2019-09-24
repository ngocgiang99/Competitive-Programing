#include <cstdio>
#include <algorithm>
#include <cstring>
#define P1 31ll
#define P2 53ll
#define M1 1000000007
#define M2 998244353
#define pii pair<int,int>
using namespace std;
 
int n;
char now[1000010],pre[1000010];
int len;
 
int check()
{
    int i=len,j=1;
    pii hpre={0,0},hnow={0,0};
    long long tmp1=1,tmp2=1;
    int re=0;
    while (pre[i] && now[j])
    {
        hpre.first=(hpre.first+(pre[i]*tmp1)%M1)%M1;
        hpre.second=(hpre.second+(pre[i]*tmp2)%M2)%M2;
        hnow.first=((hnow.first*P1)%M1+now[j])%M1;
        hnow.second=((hnow.second*P2)%M2+now[j])%M2;
        if (hnow==hpre) re=j;
        tmp1=(tmp1*P1)%M1;
        tmp2=(tmp2*P2)%M2;
        i--;
        j++;
    }
    return re;
}
 
int main()
{
    freopen("E.inp", "r", stdin);
    freopen("E.ans", "w", stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",now+1);
        int t=0;
        if (i>1) t=check();
        for (int j=t+1;now[j];j++)
        {
            pre[++len]=now[j];
        }
    }
    printf("%s",pre+1);
    return 0;
}