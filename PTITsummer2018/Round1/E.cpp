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
int t[MAXN], s[MAXN];
int l1, l2, sum1, sum2;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> n;
    FORE(i,1,n) cin>> t[i];

    l1 = 1;
    l2 = 1;
    FORE(i,1,n) {
        s[i] = 6000;

        while(t[i] - t[l1] > 120) {
            sum1 -= s[l1];
            ++l1;
        }

        s[i] = min(s[i], max(0, 15000 - sum1));

        while(t[i] - t[l2] > 1440) {
            sum2 -= s[l2];
            ++l2;
        }

        s[i] = min(s[i], max(0, 40000 - sum2));

        sum1 += s[i];
        sum2 += s[i];

        cout<< s[i] <<endl;
    }


    return 0;
}