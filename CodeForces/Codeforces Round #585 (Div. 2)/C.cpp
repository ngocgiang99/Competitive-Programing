#include <bits/stdc++.h>
using namespace std;
#define FORE(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORIT(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define fi first
#define se second
#define ll long long
#define mp make_pair
#define pb push_back
#define all(a) a.begin(),a.end()
#define sqr(x) (x)*(x)
#define endl '\n'

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
const int N = 500;
typedef pair<int, int> ii;
int n, ans;
char a[MAXN], b[MAXN];
ii res[MAXN];

void process() {
    int suma = 0;
    FORE(i,1,n) {
        suma = suma + (a[i] == 'a') + (b[i] == 'a');
    }
    if (suma&1) {
        cout<< -1 <<endl;
        return ;
    }

    int ca = 0, cb = 0;
    FORE(i,1,n)
    if (a[i] == b[i]) continue;
    else {
        if (a[i] == 'a') {
            if (ca == 0) ca = i;
            else {
                ++ans;
                res[ans] = ii(ca, i);
                ca = 0;
            }
        }
        else {
            if (cb == 0) cb = i;
            else {
                ++ans;
                res[ans] = ii(cb, i);
                cb = 0;
            }
        }
    }

    if (ca && cb) {
        ans += 2;
        res[ans-1] = ii(ca, ca);
        res[ans] = ii(ca, cb);
    }
    cout<< ans <<endl;
    FORE(i,1,ans)
    cout<< res[i].fi <<' '<< res[i].se <<endl;

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    // freopen("input.inp", "r", stdin);
    // freopen("output.out", "w", stdout);
    #endif
    cin>> n;
    cin>> a+1;
    cin>> b+1;

    process();


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}