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
typedef pair<int,int> ii;

int n, m;
int d[MAXN], cl[MAXN], x[MAXN];
priority_queue<ii> h;
vector<int> a[MAXN];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t, test_case;
    cin>> t;
    FORE(test_case,1,t) {
        cin>> n >> m;

        FORE(i,1,n) a[i].clear();
        FORE(i,1,m) {
            int u, v;
            cin>> u >> v;
            a[u].pb(v);
            a[v].pb(u);
        }
        FORE(i,1,n) sort(all(a[i]));

        FORE(i,1,n) d[i] = a[i].size(); 
        //FORE(i,1,n) a[i].pb(0);
        FORE(i,1,n) cl[i] = 0;
        while(h.size()) h.pop();

        FORE(i,1,n) 
        if  (d[i] == 2) h.push(ii(-d[i], i));

        //int pp = binary_search(a[1].begin(),a[1].end(),2);
        //cout<< pp <<endl;

        while(true) {
            if (!h.size()) break;
            int du = -h.top().fi;
            int u = h.top().se;
            h.pop();
            if (du != d[u]) continue;
            //if (du < 2) continue;


            int ok = 1;
            int len = 0;
            FOR(i,0,a[u].size()) { 
                int v = a[u][i];
                if (!cl[v]) x[++len] = v;
            }
            //cout<< u <<' '<< len <<' '<< x[1] <<' '<< x[2] <<endl;
            if (len == 2)
            if (binary_search(a[x[1]].begin(),a[x[1]].end(),x[2]) ) {
                cl[u] = 1;
                d[x[1]]--;
                d[x[2]]--;
                //cout<< u <<' '<< "A" <<endl;
                if (d[x[1]] == 2)
                    h.push(ii(-d[x[1]], x[1]));
                if (d[x[2]] == 2) 
                    h.push(ii(-d[x[2]], x[2]));
            }
        }
        
        int ans = n;
        FORE(i,1,n) {
            ans -= cl[i];
            //if (!cl[i]) cout<< i <<endl;
        }

        cout<< "Case #"<< test_case <<endl;
        cout<< ans <<endl;
    }

    return 0;
}