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



const int MAXN = 1e5 + 5;
const int base = 1e9 + 7;
const int N = 5000;

int n, mx;
string s[MAXN];
int po[2][10*MAXN];
vector<int> h[2][MAXN];
int Mod[2] = {1000000753, 1000000447};

int getHash(int x, int i, int l, int r) {
    return (1ll*h[x][i][r] - 1ll*h[x][i][l-1]*po[x][r-l+1]%Mod[x] + 1ll*Mod[x]*Mod[x]) % Mod[x];
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("E.inp", "r", stdin);
    freopen("E.out", "w", stdout);

    cin>> n;
    FORE(i,1,n) {
        cin>> s[i];
        //cout<< i <<' '<< s[i].size() <<endl;
        int len = s[i].size();
        mx = max(len, mx);
    }

    po[0][0] = 1; po[0][1] = 73;
    po[1][0] = 1; po[1][1] = 57;
    
    FORE(x,0,1)
    FORE(i,2,mx) po[x][i] = 1ll*po[x][i-1] * po[x][1] % Mod[x]; 

    FORE(x, 0, 1)
    FORE(i,1,n) {
        h[x][i].pb(0);
        FORE(j, 1, s[i].size())
        h[x][i].pb((1ll*h[x][i][j-1]*po[x][1] + s[i][j-1]) % Mod[x]); 
    }
    // FORE(i,1,n) {
    //     FORE(j,1,s[i].size())
    //     cout<< h[i][j] <<' ';
    //     cout<<endl;
    // }

    //cout << getHash(0, 1, 4, 6) << " " << getHash(0, 2, 1, 3) <<endl;
    //cout << getHash(1, 1, 4, 6) << " " << getHash(1, 2, 1, 3) <<endl;

    cout << s[1] ;
    FORE(i,2,n) {
        int jmax = 0;
        FORE(j, 1, s[i].size())
        if (j <= s[i-1].size() && 
            getHash(0, i-1, s[i-1].size() - j + 1, s[i-1].size()) == getHash(0, i, 1, j) &&
            getHash(1, i-1, s[i-1].size() - j + 1, s[i-1].size()) == getHash(1, i, 1, j)) {
            jmax = j;
        }

        //cerr<< i <<' '<< jmax <<' '<< s[i].size() <<endl;

        FOR(j, jmax, s[i].size()) {
            //cerr << ' '<<  i <<' '<< j <<endl;
            cout<< s[i][j] ;
        }
    }



    return 0;
}