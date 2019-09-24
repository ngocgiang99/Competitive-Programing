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



const int MAXN = 1e6 + 50;
const int base = 1e9 + 7;
const int N = 5000;

int l, r;
int g[MAXN], cnt[MAXN];

void sangnt() {
    int x = sqrt(MAXN);
    FORE(i,2,x) 
    if (!g[i]){
        for (int j = i*i; j < MAXN; j += i)
        g[j] = i;
    }      
    FOR(i,2,MAXN)
    if (g[i] == 0) g[i] = i;
}

void input() {
    cin>> l >> r;
}

void prepare() {
    FORE(i,1,r) cnt[i] = 0;
}

void pt(int x) {
    int xx = x;
    int res = 1;
    int prev = -1;
    while(x > 1) {
        if (g[x] != prev) {
            prev = g[x];
            res *= g[x];
        }
        while(x%prev == 0) x /= prev;
    }
    //cout<< xx <<' '<< res <<endl;
    ++cnt[res];
}

void process() {
    FORE(i, l, r)
    pt(i);

    long long ans = 0;
    FORE(i,1,r) {
        //cout<< i <<' '<< cnt[i] <<endl;
        ans = ans + 1ll*cnt[i]*(cnt[i]-1)/2;
    }
    cout<< ans <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("EP.inp", "r", stdin);
    freopen("EP.out", "w", stdout);
    sangnt();
    int t;
    cin>> t;
    while(t--) {
        input();
        prepare();
        process();
    }




    return 0;
}