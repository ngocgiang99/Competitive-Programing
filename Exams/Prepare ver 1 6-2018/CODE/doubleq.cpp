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



const int MAXN = 1e6 + 50;
const int base = 1e9 + 7;
const int N = 5000;
const string NAME = "doubleq";
typedef pair<int,int> ii;

int x;
int a[MAXN];
set<ii> smax,smin;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("doubleq.inp", "r", stdin);
    freopen("doubleq.out", "w", stdout);
    #endif
    //memset(a, -1, sizeof a);
    int cnt = 0;
    while(cin>> x) {
        if (x == 0) break;
        ++cnt;
        //cout<< cnt <<' '<< smax.size() <<' '<< smin.size() <<endl; 
        if (x == 1) {
            int k, p;
            cin>> k >> p;
            //cout<< x <<' '<< k <<' '<< p <<endl;
            smax.insert(ii(-p,k));
            smin.insert(ii(p,k));
            //a[k] = p;
        }
        if (x == 2) {
            if (!smax.size()) {
                cout<< 0 <<endl;
                continue;
            }
            ii u = *smax.begin();
            //cout<< u.se <<' '<< u.fi <<endl;
            cout<< u.se <<endl;
            smax.erase(u);
            smin.erase(ii(-u.fi,u.se));
        }
        if (x == 3) {
            if (!smin.size()) {
                cout<< 0 <<endl;
                continue;
            }
            ii u = *smin.begin();
            //cout<< u.se <<' '<< u.fi <<endl;
            cout<< u.se <<endl;
            smin.erase(u);
            smax.erase(ii(-u.fi,u.se));
        }

        //if(system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0);
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
