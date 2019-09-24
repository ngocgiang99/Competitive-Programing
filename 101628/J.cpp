#include <bits/stdc++.h>
using namespace std;
#define FORE(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)

#define fi first
#define se second
#define ll long long
#define mp make_pair
#define pb push_back
#define all(a) a.begin(),a.end()
#define sqr(x) (x)*(x)

template <typename G> inline void read(G &x)
{
    x = 0; char c; int dau = 1;
    while(!isdigit(c = getchar())) {if (c == '-') dau = -1;};
    do{x = x*10 + c - '0';} while(isdigit(c = getchar()));
    x = dau*x;
}

template <typename G> inline void write(G x)
{
    if (x > 9) write(x/10);
    putchar(x%10 + '0');
}

template <class T> inline T min(T a,T b,T c){ return min(a,min(b,c)); }
template <class T> inline T min(T a,T b,T c,T d) { return min(a,min(b,c,d)); }
template <class T> inline T max(T a,T b,T c){ return max(a,max(b,c)); }
template <class T> inline T max(T a,T b,T c,T d) { return max(a,max(b,c,d)); }



const int MAXN = 1e5 + 50;
const int base = 1e9 + 7;
const int N = 5000;
struct data {
    int a, b, c;
}a[MAXN];


int n;
long long k;



int check(int x) {
    long long cnt = 0;
    long long res = 0;
    FORE(i,1,n)
    if (a[i].a > x) {
        cnt += (a[i].a - x);
        res += 1ll*a[i].b*(a[i].a - x);
    }

    if (res > k) return 0;

    FORE(i,1,n)
    if (cnt && a[i].a < x) {
        int r = x - a[i].a; 
        if (cnt > r) {
            cnt -= r;
            res += 1ll*r*a[i].c;
        }
        else {
            //cnt = 0;
            res += 1ll*cnt*a[i].c;
            cnt = 0;
        }
        if (res > k) return 0;
    }
    //cout<< x <<' '<< cnt <<' '<< res <<endl;
    if (cnt == 0 && res <= k) return 1;
    return 0;
}

int cmp(data a, data b) {
    return a.c < b.c;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> n >> k;
    FORE(i,1,n) cin>> a[i].a >> a[i].b >> a[i].c;

    sort(a+1, a+n+1, cmp);

    int lef = 0, rig = 1e6;
    int ans = 0;
    while(lef <= rig) {
        int mid = (lef + rig) >> 1;

        if (check(mid)) {
            ans = mid;
            rig = mid - 1;
        }
        else 
            lef = mid + 1;
    }

    cout<< ans <<endl;
    return 0;
}