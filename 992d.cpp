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


int n, k;
int ans;
int a[MAXN], pre[MAXN];
long long s[MAXN];

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> n >> k;
    FORE(i,1,n) {
        cin>> a[i];
        if (a[i-1] > 1) pre[i] = i-1;
        else pre[i] = pre[i-1];
        pre[1] = 1;
    }
    FORE(i,1,n) s[i] = s[i-1] + a[i];

    a[0] = 1;
    FORE(i,1,n) {
        long long mul = a[i];
        long long sum = a[i];
        int j1, j2 = i, x;
        long long k1 = k;
        while(true) {
            j1 = pre[j2];
            if (j1 != i) mul = mul*a[j1];
            long long sum = s[i] - s[j1-1];
            if (k1 > 1) {
                x = gcd(mul, k1);
                mul /= x;
                k1 /= x;
            }
            if (mul - k1*sum > j2-1) {
                k1 = k1*x;
                mul = mul*x;
                if (j1 != i) mul = mul / a[j1];
                if (k1 > 1) break;
                cout<< i <<' '<< mul <<' '<< sum <<' '<< j2 <<' '<< j1 <<endl;
                if (mul - sum < j2 - j1 - 1) ++ans;

                break;
            }

            j2 = j1;
            if (j2 == 1) {
                if (mul == k1*sum) ++ans;
                break;
            }
        }
    }

    cout<< ans <<endl;
    return 0;
}