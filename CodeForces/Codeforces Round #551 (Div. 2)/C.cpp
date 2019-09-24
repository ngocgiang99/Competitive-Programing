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
const int N = 5000;

int n;
int a[MAXN], b[MAXN];
char ch[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("new.inp", "r", stdin);
    //freopen("new.out", "w", stdout);
    #endif
    cin>> n;
    FORE(i,1,n) cin>> ch[i];

    if (n&1 || ch[n] == '(') {
        cout<< ":(" <<endl;
        return 0;
    }
    ch[n] = ')';

    FORD(i,n,1) {
        int x = 0;
        if (ch[i] == '(') x = 1;
        else if (ch[i] == ')') x = -1;

        a[i] = a[i+1] + x;
        if (ch[i] == '?') b[i] = b[i+1] + 1;
        else b[i] = b[i+1];
    }

    int cnt = 0;
    FORE(i,1,n) {
        if (ch[i] == '(') ++cnt;
        else if (ch[i] == ')') --cnt;
        else {
            if (cnt > 1 && cnt + b[i] + a[i] > 0) {
                --cnt;
                ch[i] = ')';
            }
            else {
                ++cnt;
                ch[i] = '(';
            }
        }
        if (cnt <= 0 && i < n) {
            cout<< ":(";
            return 0;
        }
    }

    if (cnt) {
        cout<< ":(";
        return 0;
    }

    FORE(i,1,n)
    cout<< ch[i];
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
