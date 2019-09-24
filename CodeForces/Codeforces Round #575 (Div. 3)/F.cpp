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

typedef pair<int,int> pii;
typedef pair<long long, pii> plii;
struct Edge {
    int u, v;
    int w;
} e[MAXN];

int n, m, k;
map<pii, long long> ma;
set<plii> h;
set<plii> ::iterator it;
vector<pii> a[MAXN];

int cmp(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

void dijkstra() {

    FORE(i,1,n) ma[pii(i, i)] = 0;

    FORE(i, 1, min(m, k)) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        //cout<< u <<' '<< v <<' '<< w <<endl;
        h.insert(plii(w, pii(u, v)));
        ma[pii(u, v)] = w;
        ma[pii(v, u)] = w;
    }

    //system("pause");
    long long thresh = 1e15;
    if (m >= k) thresh = e[k].w;

    int cnt = 0;

    while(cnt < k) {
        long long dist = (*h.begin()).fi;
        int u1 = (*h.begin()).se.fi;
        int u2 = (*h.begin()).se.se;
        h.erase(h.begin());
        //cout<< u1 <<' '<< u2 <<' '<< dist <<' '<< h.size() << ' '<< cnt <<endl;
        //system("pause");

        if (dist != ma[pii(u1, u2)]) continue;
        ++cnt;
        if (cnt == k) {
            cout<< dist <<endl;
            return;
        }

        for (int i = 0; int v = a[u1][i].fi; ++i) 
        if (dist + a[u1][i].se < thresh) {
            if (ma.find(pii(u2, v)) == ma.end() || ma[pii(u2, v)] > dist + a[u1][i].se) {
                long long newDist = dist + a[u1][i].se;
                ma[pii(u2, v)] = newDist;
                ma[pii(v, u2)] = newDist;
                //cout<< "Push new item: " << u2 <<' '<< v <<' '<< newDist <<endl;
                if (newDist < thresh)
                h.insert(plii(newDist, pii(u2, v)));
            }
        }

        for (int i = 0; int v = a[u2][i].fi; ++i) 
        if (dist + a[u2][i].se < thresh) {
            if (ma.find(pii(u1, v)) == ma.end() || ma[pii(u1, v)] > dist + a[u2][i].se) {
                long long newDist = dist + a[u2][i].se;
                ma[pii(u1, v)] = newDist;
                ma[pii(v, u1)] = newDist;
                //cout<< "Push new item: " << u1 <<' '<< v <<' '<< newDist <<endl;
                //if (newDist < thresh)
                h.insert(plii(newDist, pii(u1, v)));
            }
        }

        int setCnt = 0;
        set<plii> ::iterator it = h.begin();
        while(it != h.end()) {
            ++setCnt;
            if (setCnt > k) {
                plii old = *it;
                ++it;
                h.erase(old);
            }
            else ++it;
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> n >> m >> k;
    FORE(i,1,m) {
        cin>> e[i].u >> e[i].v >> e[i].w;
        a[e[i].u].pb(pii(e[i].v, e[i].w));
        a[e[i].v].pb(pii(e[i].u, e[i].w));
    }
    

    FORE(i,1,n) a[i].pb(pii(0, 0));

    sort(e+1, e+m+1, cmp);

    dijkstra();


    return 0;
}