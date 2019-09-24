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
const int N = 50;

int getindex(int i, int ind);

int m, m1, m2;
int n, ans, r;
char ch[MAXN];
int f[N], cnt[N][30], pos[MAXN], sum[N];
pair<int, int> res[N];

void input() {
    cin>> m >> m1 >> m2 >> r;
    FORE(i,1,m) cin>> ch[i];
}

void prepare() {
    f[1] = m1; f[2] = m2;
    n = 2;

    do {
        ++n;
        f[n] = f[n-1] + f[n-2];
    }while(f[n] <= m);

    FORE(i,1,m1+m2)
    pos[i] = i;

    FORD(i,m,1) 
    if (pos[i] == 0) {
        int ind = lower_bound(f+1, f+n+1, i) - f;

        pos[i] = getindex(i, ind);
    }

    //FORE(i,1,m)
    //cout<< pos[i] <<' ';
    //cout<<endl;

    FORE(i,1,m) {
        ++cnt[pos[i]][ch[i] - 'A'];
        //cout<< pos[i] <<' '<< cnt[pos[i]][ch[i] - 'A'] <<' '<< ch[i] <<endl;
    }
}

void process() {
    FORE(i,1,m1+m2) {
        FORE(j,0,25) sum[i] += cnt[i][j];
        //cout<< i <<' '<< sum[i] <<endl;

        FORE(j,0,25) {
            if (ch[i] - 'A' == j) {
                continue;
            }

            /*if (cnt[i][j] + 1 > res[i].fi) {
                cout<< i <<' '<< (char) ('A' + j) <<' '<< cnt[i][j] + 1 <<endl;
            }*/

            res[i] = max(res[i], make_pair(cnt[i][j] + 1, i));
        }
    }
    //cout<< ans <<endl;

    sort(res+1, res+m1+m2+1);
    //FORE(i,1,m1+m2)
    //cout<< res[i].fi <<' '<< res[i].se <<endl;

    FORE(i,1,m1+m2)        
    if (m1+m2-i < r) ans += (sum[res[i].se] - res[i].fi);
    else ans += (sum[res[i].se] - cnt[res[i].se][ch[res[i].se] - 'A']);
    //cout<< res[i].se <<' '<< sum[res[i].se] <<' '<< cnt[res[i].se][ch[res[i].se] - 'A'] <<endl;

    cout<< ans <<endl;
}

int getindex(int i, int ind) {
    //cout<< i <<' '<< ind <<endl;
    if (pos[i] != 0) return pos[i];

    if (i > f[ind-1]) return getindex(i - f[ind-1], ind-2);
    else return getindex(i, ind-1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("COMSTR.inp", "r", stdin);
    freopen("COMSTR.out", "w", stdout);
    
    input();
    prepare();
    process();

    return 0;
}