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

int a[N], b[N];
long long ans;

long long getans() {
    long long res = 0;
    FOR(i,0,14)
    if(b[i]%2 == 0) res += b[i];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n = 14;
    FOR(i,0,n) cin>> a[i];

    FOR(i,0,n) 
    if (a[i]) {
        int pos = i;
        FOR(j,0,n) b[j] = a[j];
        int cnt = b[i];
        b[i] = 0;

        pos = (pos + 1)%14;
        while(pos != 0 && cnt) {
            --cnt;
            b[pos]++;
            pos = (pos + 1)%14;
        }

        if (cnt == 0) {
            ans = max(ans, getans());
            continue;
        }
        

        FOR(j,0,n)
        b[j] += cnt/14;
        cnt %= 14;

        //cout<< pos <<' '<< cnt <<endl;
        while(cnt) {
            ++b[pos];
            --cnt;
            pos = (pos + 1)%14;
        }
        cout<< "(" << i << ")" <<' ';
        FOR(j,0,n)
        cout<< b[j] <<' ';
        cout<<endl;

        ans = max(ans, getans());
    }

    cout<< ans <<endl;

    return 0;
}