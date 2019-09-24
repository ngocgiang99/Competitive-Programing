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

int m, n;
int ans;
int lef[MAXN], rig[MAXN], h[MAXN];

void buildleft() {
    stack<int> st;
    FORE(i,1,n) {
        while(st.size() && h[i] <= h[st.top()]) st.pop();
        if (st.size()) lef[i] = st.top();
        else lef[i] = 0;
        st.push(i);
    }
}

void buildright() {
    stack<int> st;
    FORD(i,n,1) {
        while(st.size() && h[i] <= h[st.top()]) st.pop();
        if (st.size()) rig[i] = st.top();
        else rig[i] = n+1;
        st.push(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("maxrec.inp", "r", stdin);
    freopen("maxrec.out", "w", stdout);
    #endif
    cin>> m >> n;
    FORE(i,1,m) {
        FORE(j,1,n) {
            char ch;
            cin>> ch;
            if (ch == '1') h[j] = h[j] + 1;
            else h[j] = 0;
        }

        buildleft();
        buildright();

        FORE(j,1,n) 
        ans = max(ans, h[j]*(rig[j] - lef[j] - 1));
    }

    cout<< ans <<endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
