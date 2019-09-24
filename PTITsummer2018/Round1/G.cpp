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



struct PS {
    long long x, y;

};

int n;
string ans;

PS a[N], origin;

PS New(long long _x, long long _y) {
    PS res;
    res.x = _x;
    res.y = _y;
    return res;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else 
        return gcd(b, a%b);
}

PS add(PS a, PS b) {
    long long A = a.x*b.y + a.y*b.x;
    long long B = a.y*b.y;

    long long C = gcd(A, B);
    A = A/C;
    B = B/C;
    
    return New(A, B);
}

string tostring(int digit) {
    string res = "";
    res += (digit + '0');
    return res;
}

void writeans() {
    long long xx = origin.x / origin.y;
    origin.x %= origin.y;

    if (origin.x == 0) {
        cout<< xx;
        return;
    }

    ans = '.';
    int cnt = 0;

    while(cnt < 400000 && origin.x != 0) {
        origin.x *= 10;
        long long q = origin.x / origin.y;
        ans += (q + '0');

        origin.x -= origin.y * q;
        ++cnt;
    }
    
    //cout<< cnt <<endl;
    if (cnt == 400000) {
        origin.x *= 10;
        long long q = origin.x / origin.y;

        //cout<< q <<endl;
        if (q >= 5) q = 1;
        else q = 0;

        //cout<< q <<endl;
        int pos = ans.size() - 1;
        while(ans[pos] != '.' && q) {
            if (ans[pos] == '9') {
                ans[pos] = '0';
                q = 1;
            }
            else {
                ++ans[pos];
                q = 0;
            }
        }
        if (q) ++xx;
    }
    

    cout<< xx << ans <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("G.out", "w", stdout);

    cin>> n;
    FORE(i,1,n) cin>> a[i].x >> a[i].y;

    origin = a[1];

    FORE(i,2,n) origin = add(origin, a[i]);

    writeans();


    return 0;
}