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
const int N = 150;

int n, lens;
int f[N][N], a[N][5], len[N][5];
char s[N], c[N][4][15];

int ans;


void init() {
    cin>> s+1;
    cin>> n;
    FORE(i,1,n) cin>> c[i][0]+1;
}

int checkpalin(int i) {
    int leng = len[i][0];
    int lef = 1;
    int rig = leng;

    while(lef < rig) {
        if (c[i][0][lef] != c[i][0][rig]) return 0;
    }

    return 1;
}

int check(int ind, int type, int lef, int iind, int ttype) {
    int i = 1;
    int leng = strlen(c[iind][ttype] + 1);
    
    while(i <= leng) {
        if (c[ind][type][lef + i - 1] != c[iind][ttype][i]) return 0;  
        ++i;
    }

    return 1;
}

void checkeven(int ind, int type) {
    int leng = len[ind][type];
    int ok[leng+1];

    FORE(i, 0, leng) ok[i] = 0;
    ok[0] = 1;

    FORE(i,1,leng)
    FORE(j,1,n)
    if (i >= strlen(c[j][0] + 1) && check(ind, type, i - strlen(c[j][0] + 1) + 1, j, 0)) {
        //if (ind == 1 && type == 0) cout<< i <<' '<< j <<endl;
        ok[i] = ok[i] | ok[i - strlen(c[j][0] + 1)];
        if (ok[i] == 1) break;
    }

    a[ind][1-type] = ok[leng];
}

void checkodd(int ind, int type) {
    int leng = len[ind][type];
    int ok[leng+1];

    FORE(i, 0, leng) ok[i] = 0;
    ok[0] = 1;
    //if (ind == 1 && type == 3) cout<< leng <<' '<< ok[leng] <<endl;

    FORE(i,1,leng)
    FORE(j,1,n)
    if (i >= strlen(c[j][0] + 1) && check(ind, type, i - strlen(c[j][0] + 1) + 1, j, 0)) {
        //if (ind == 1 && type == 3) cout<< i <<' '<< j <<endl;
        ok[i] = ok[i] | ok[i - strlen(c[j][0] + 1)];
        if (ok[i] == 1) break;
    }

    a[ind][5-type] = ok[leng];
}

int addlef(int l, int ind, int type) {
    int leng = len[ind][type];
    //cout<< l <<' '<< ind <<' '<< type <<' '<< "BUG1" << endl;

    FORE(i, 1, leng) 
    if (s[l+1] == c[ind][type][i]) {
        ++l;
    }
    
    //cout<< l <<' '<< ind <<' '<< type <<' '<< "BUG2" << endl;

    return l;
}

int addrig(int r, int ind, int type) {
    int leng = len[ind][type];

    FORD(i, leng, 1) 
    if (s[r-1] == c[ind][type][i]) {
        --r;
    }
    
    return r;
}

void prepare() {
    FORE(i,1,n) {
        int leng = strlen(c[i][0] + 1);
        FORE(j,1,leng) {
            c[i][1][leng - j + 1] = c[i][0][j];
            if (j < leng) c[i][2][j] = c[i][0][j];
            if (j > 1) c[i][3][leng - j] = c[i][0][j];
        }
        len[i][0] = len[i][1] = leng;
        len[i][2] = len[i][3] = leng-1;

        if (checkpalin(i)) a[i][4] = 1;

    }

    FORE(i,1,n) {
        checkeven(i, 0);
        checkeven(i, 1);
        checkodd(i, 2);
        checkodd(i, 3);
        cout<< a[i][0] <<' '<< a[i][1] <<' '<< a[i][2] <<' '<< a[i][3] <<endl;
    }

    lens = strlen(s+1);
    FORE(l,0,lens+1)
    FORE(r,0,lens+1) f[l][r] = base;

    f[0][lens+1] = 0;
    ans = base;
}

void process() {
    //int lens = strlen(s+1);
    
    cout<< f[0][lens+1] <<endl;
    FORE(l,0,lens)
    FORD(r,lens+1,l) 
    if (f[l][r] != base) {
        cout<< l <<' '<< r <<endl;
        cout<< f[l][r] <<endl;
        FORE(i,1,n) {
            if (a[i][0]) {
                int lef = addlef(l, i, 0);
                int rig = addrig(r, i, 1);
                int ln = strlen(c[i][0] + 1);
                cout<< 0 <<' '<< i <<' '<< lef <<' '<< rig <<endl;

                f[lef][rig] = min(f[lef][rig], f[l][r] + 2*ln );
                if (lef + 1 >= rig) {
                    
                    ans = min(ans, f[l][r] + 2*ln);
                }
            }
            if (a[i][1]) {
                int lef = addlef(l, i, 1);
                int rig = addrig(r, i, 0);
                int ln = strlen(c[i][0] + 1);
                cout<< 1 <<' '<< i <<' '<< lef <<' '<< rig <<endl;

                f[lef][rig] = min(f[lef][rig], f[l][r] + 2*ln);
                if (lef + 1 >= rig) {
                    
                    ans = min(ans, f[l][r] + 2*ln);
                }
            }
            if (a[i][2]) {
                int lef = addlef(l, i, 0);
                int rig = addrig(r, i, 2);
                cout<< 2 <<' '<< i <<' '<< lef <<' '<< rig <<endl;

                if (lef + 1 >= rig) {
                    int ln = strlen(c[i][2] + 1);
                    ans = min(ans, f[l][r] + 2*ln + 1);
                }
            }
            if (a[i][3]) {
                int lef = addlef(l, i, 3);
                int rig = addrig(r, i, 0);
                cout<< 3 <<' '<< i <<' '<< lef <<' '<< rig <<endl;

                if (lef + 1 >= rig) {
                    int ln = strlen(c[i][3] + 1);
                    ans = min(ans, f[l][r] + 2*ln + 1);
                }
            }
        }

        if (a[i][4]) {
            lef = addlef(l, i, 4);
        }
    }

    cout<< ans <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("wordgame.inp", "r", stdin);
    freopen("wordgame.out", "w", stdout);
    init();
    prepare();
    process();
    

    return 0;
}