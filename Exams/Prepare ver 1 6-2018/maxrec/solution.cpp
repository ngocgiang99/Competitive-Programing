// Program: MAXREC
// Writen by Le Thanh Binh - 8/2013

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int m, n, a[1005][1005], h[1005], s[1005], sn;
int prev[1005], next[1005];

int main() {
    freopen("maxrec.inp","r",stdin);
    freopen("mexrec.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    int ret=0;
    memset(h,0,sizeof(h));
    h[0]=h[n+1]=-1;
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) if (a[i][j]) h[j]++; else h[j]=0;
        sn=0;
        for(int j=1;j<=n;j++)
        if (h[j]>h[j-1]) {prev[j]=j; s[++sn]=j;} else {
            while (sn && h[s[sn]]>=h[j]) sn--; sn++;
            prev[j]=prev[s[sn]];
            s[sn]=j;
        }
        sn=0;
        for(int j=n;j>=1;j--)
        if (h[j]>h[j+1]) {next[j]=j; s[++sn]=j;} else {
            while (sn && h[s[sn]]>=h[j]) sn--; sn++;
            next[j]=next[s[sn]];
            s[sn]=j;
        }
        for(int j=1;j<=n;j++) ret=max(ret,h[j]*(next[j]-prev[j]+1));
    }
    printf("%d",ret);
}
