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



const int MAXN = 5e4 + 100 ;
const int base = 1e9 + 7;
const int N = 305;
typedef pair<int,int> ii;

int n, m;
int f[N][N];
int a[MAXN], b[MAXN], nxt[MAXN], pre[MAXN], cx[MAXN];
int lef[4*MAXN], rig[4*MAXN], lazy[4*MAXN], it[4*MAXN];
ii c[MAXN];

double tupd, tget;

void init() {
    read(m); read(n);
    FORE(i,1,n) read(a[i]), read(b[i]);

    FORE(i,1,n) {
        a[i] = min(a[i], m);
        b[i] = min(b[i], m);
    }

}
//--------------------------------------
//SOLUTION sub1-2

void process_sub12() {

    FORE(i,1,m)
    FORE(j,i,m) f[i][j] = 0;

    //cout<< m <<' '<< n <<endl;
    FORE(i,1,n) {
        //cin>> l[i] >> r[i];
        int l = a[i];
        int r = b[i];

        FORD(lef,l,1)
        FORE(rig,r,m) {
            ++f[lef][rig];
            if (f[lef][rig] > rig - lef + 1) {
                //cout<< l <<' '<< r <<' '<< lef <<' '<< rig <<' '<< f[lef][rig] <<endl;
                cout<< i-1 <<endl;
                return ;
            }
        }
    }
    cout<< n <<endl;
}
//-----------------------------------------------------
//Solution sub3

int check_sub3(int x) {
    FORE(i,1,x)
        c[i] = ii(a[i], b[i]);
    sort(c+1, c+x+1);

    //cout<< x <<endl;
    FORE(i,1,x)
    if (c[i].se < i) {
        //cout<< x <<' '<< c[i].se <<' '<< i <<endl;
        return 0;
    }
    return 1;
}

void sub3() {
    int ans = 0;
    int l = 1;
    int r = n;
    //cout<< l <<' '<< r <<endl;
    while(l <= r) {
        int mid = (l + r) >> 1;

        if (check_sub3(mid)) {
            l = mid + 1;
            ans = mid;
        }
        else
            r = mid - 1;
    }
    cout<< ans <<endl;
}

//-----------------------------------------------
//Solution sub4

int cmp(ii a, ii b) {
    if (a.se != b.se) return a.se < b.se;
    return a.fi > b.fi;
    //return a.se < b.se;
}

void build(int x, int l, int r) {
    lef[x] = l; rig[x] = r;
    if (l == r) {
        lazy[x] = 0;
        it[x] = l-1;
        return;
    }

    int mid = (l + r) >> 1;
    build(2*x, l, mid);
    build(2*x+1, mid+1, r);

    it[x] = max(it[2*x], it[2*x+1]);
    lazy[x] = 0;
}

void up(int x) {
    lazy[2*x] += lazy[x];
    lazy[2*x+1] += lazy[x];
    it[2*x] += lazy[x];
    it[2*x+1] += lazy[x];

    lazy[x] = 0;
}

void upd(int x, int l, int r) {

    if (lef[x] > r || rig[x] < l) return;

    if (l <= lef[x] && rig[x] <= r) {
        lazy[x]++;
        it[x]++;
        return;
    }

    up(x);

    upd(2*x, l, r);
    upd(2*x+1, l, r);
    it[x] = max(it[2*x], it[2*x+1]);
}

int get(int x, int l, int r) {

    if (lef[x] > r || rig[x] < l) return 0;
    if (l <= lef[x] && rig[x] <= r) return it[x];

    up(x);

    return max(get(2*x, l, r), get(2*x+1, l, r));
}


int check_sub4(int x) {
    FORE(i,1,x) c[i] = ii(a[i], b[i]);

    sort(c+1, c+x+1, cmp);
    build(1,1,m);

    FORE(i,1,x) {
        //double t1, t2;
        //t1 = (double) clock() / 1000;
        upd(1, 1, c[i].fi);
        //t2 = (double) clock() / 1000;
        //cout<< t1 <<' '<< t2 <<endl;

        //tupd = max(tupd, t2 - t1);

        //t1 = (double) clock() / 1000;
        int xx = get(1, 1, c[i].fi);
        //t2 = (double) clock() / 1000;

        //tget = max(tget, t2 - t1);

        if (xx > c[i].se) return 0;
    }
    return 1;
}

void sub4() {
    int ans = 0;
    int l = 1;
    int r = min(m,n);
    while(l <= r) {
        int mid = (l + r) >> 1;

        if (check_sub4(mid)) {
            l = mid + 1;
            ans = mid;
        }
        else
            r = mid - 1;
    }

    cout<< ans <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("queue.inp", "r", stdin);
    freopen("queue.out", "w", stdout);
    #endif
    int test;
    read(test);
    cout<<fixed<<setprecision(6);
    while(test--) {
        init();

        int cnt = 0;
        FORE(i,1,n)
        if (a[i] == 1) ++cnt;
        /*if (n <= 300)
            process_sub12();
        else
        if (cnt == n) sub3();
        else*/
        tupd = 0.0;
        tget = 0.0;
            sub4();
            //sub3();
        //cout<< tupd <<' '<< tget <<endl;
        //cout<< 1.0*clock()/1000 <<endl;

    }



    //cout<< clock() <<endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
