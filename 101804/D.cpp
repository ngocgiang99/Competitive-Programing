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


int n, q;
long long a[MAXN], bit[MAXN];

void upd(int x, long long val) {
    while(x <= n) {
        bit[x] += val;
        x += x&(-x);
    }
}

long long get(int x) {
    long long res = 0;
    //cout<< res <<endl;
    while(x) {
        res += bit[x];
        //cout<< res <<endl;
        x -= x&(-x);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("D.inp", "r", stdin);
    freopen("D.out", "w", stdout);
    #endif
    cin>> n;
    FORE(i,1,n) {
        string st;
        cin>> st;
        if (st.size() == 4)
            a[i] = (st[0] - '0')*100 + (st[2] - '0')*10 + (st[3] - '0');
        else
            a[i] = 1000;
        //cout<< a[i] <<' '<< st <<endl;
    }
    //cout<<endl;

    FORE(i,1,n) upd(i, a[i]);

    cout<< fixed << setprecision(7);
    cin>> q;
    //return 0;
    while(q--) {
        long long ans, l, r, u;
        float x;
        cin>> ans;
        if (ans == 1) {
            char ch[5];
            string st;
            cin>> u;
            cin>> st;
            int xx ;
            if (st.size() == 4)
                xx = (st[0] - '0')*100 + (st[2] - '0')*10 + (st[3] - '0');
            else
                xx = 1000;
            //cout<< u <<' '<< xx - a[u] <<' '<< st <<endl;
            upd(u, xx - a[u]);
            a[u] = xx;
        }
        else {
            cin>> l >> r;
            long long sum = get(r) - get(l-1);
            long long mau = 100*(r - l + 1);
            double t = 1.0;
            //cout<< sum <<endl;
            cout<< t*sum / mau <<endl;
        }
        //cout<< bit[1] <<' '<< get(1) <<endl;
    }


    return 0;
}
