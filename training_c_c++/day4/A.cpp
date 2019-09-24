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
long long ans;
int a[MAXN], b[MAXN];

void init() {
    cin >> n;
    FORE(i,1,n) cin>> a[i];
    FORE(i,1,n) cin>> b[i];
}

int cmp(int a, int b) {
    return a > b;
}

void process() {
    ans = 0;
    sort(a+1, a+n+1);
    sort(b+1, b+n+1, cmp);
    FORE(i,1,n)
    ans += 1ll * a[i] * b[i];
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test;
    cin>>test;
    for (int iTest = 1; iTest <= test; ++iTest) {
        init();
        process();
        cout<< "Case #" << iTest << ": " << ans << endl;
    }



    return 0;
}