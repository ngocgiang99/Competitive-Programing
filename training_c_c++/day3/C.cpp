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



const int MAXN = 1e5 * 5;
const int base = 1e9 + 7;
const int N = 5000;

int n;
int ans;
int a[MAXN];
int f[MAXN], bit[MAXN];
vector<int> v;

int get(int x) {
    int res = 0;
    while(x) {
        res = max(res, bit[x]);
        x -= x&(-x);
    }
    return res;
}

void upd(int x, int value) {
    while (x <= n) {
        bit[x] = max(bit[x], value);
        x += x&(-x);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> n;
    FORE(i,1,n) cin>> a[i], v.push_back(a[i]);

    sort(v.begin(), v.end());

    FORE(i,1,n) {
        int x = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        f[i] = get(x) + 1;
        upd(x, f[i]);
        ans = max(ans, f[i]);
    }
    cout<< ans <<endl;

    return 0;
}