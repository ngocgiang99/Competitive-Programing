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



const int MAXN = 1e6 + 7;
const int base = 1e9 + 7;
const int N = 5000;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, t;
int p[MAXN], ans[MAXN];
char a[MAXN];
set<ii, greater<ii> > Set;
ii q[MAXN];

void preprocess() {
    int k = 0;

    FORE(i,2,n) {
        while(k > 0 && a[k+1] != a[i]) k = p[k];
        if (a[k+1] == a[i]) ++k;
        p[i] = k;
        set<ii>::iterator it = Set.lower_bound(ii(k, i-k+1));

        if (it != Set.end() && (*it).fi == k) Set.erase(it);
        if (k)
        Set.insert(ii(k, i - k + 1));
    }
    Set.insert(ii(0, n+1));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> a+1; n = strlen(a+1);
    preprocess();
    cin>> t;
    FORE(i,1,t) cin>> q[i].fi, q[i].se = i;
    sort(q+1, q+t+1);
    
    // cout<< Set.size() <<endl;
    // for (set<ii>::iterator it = Set.begin(); it != Set.end(); ++it) 
    // cout<< (*it).fi << " " << (*it).se <<endl;
    FORE(i,1,t) {
        int curPos = q[i].fi;
        while ((*Set.begin()).se < curPos) {
            ii cur = *Set.begin();
            Set.erase(Set.begin());
            
            int k = p[cur.first];
            int pos = cur.se;
            while(k > 0 && pos + cur.fi - k < curPos) k = p[k];
            if (k) {
                set<ii>::iterator it = Set.lower_bound(ii(k, pos + cur.fi - k));
                if (it != Set.end() && (*it).fi == k) Set.erase(it);
                Set.insert(ii(k, pos + cur.fi - k));
            }
        }

        if (curPos == 1) ans[q[i].se] = n;
        else
        ans[q[i].se] = (*Set.begin()).fi;
    }

    FORE(i,1,t)
    cout<< ans[i] <<endl;

    return 0;
}