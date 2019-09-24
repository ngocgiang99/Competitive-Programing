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
int d[MAXN];
queue<int> q;
vector<int> a[MAXN];


int check() {
    if (n == 1) return 1;

    int x;
    cin>> x;
    q.push(1);
    if (x != 1) return 0;

    int cnt = 1;
    while(true) {
        int u = q.front(); q.pop();
        if (u != 1) --d[u];

        while(d[u]) {
            int v;
            cin>> v;
            ++cnt;

            //cout<< u <<' '<< v <<' '<< binary_search(all(a[u]), v) <<endl;
            if (binary_search(all(a[u]), v)) --d[u];
            else return 0;
            q.push(v);

            if (cnt == n) return 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("new.inp", "r", stdin);
    //freopen("new.out", "w", stdout);
    #endif
    cin>> n;
    FOR(i,1,n) {
        int u, v;
        cin>> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    FORE(i,1,n) sort(all(a[i])), d[i] = a[i].size();


    if (check()) cout<< "Yes";
    else cout<< "No";

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
