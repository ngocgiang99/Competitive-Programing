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



const int MAXN = 1e5 * 5 + 10;
const int base = 1e9 + 7;
const int N = 5000;


int n, q;
int rep, m;
int Hash[MAXN], M[MAXN], len[30];
string s[10];
char jump[30];
set<int> S[30];


void build(int h[], int x, int n) {

    FORE(i,1,n)
    Hash[i] = (1ll*Hash[i-1] * M[1] + s[x][i-1])%base;
}

int get(int l, int r) {
    return (1ll*Hash[r] - 1ll*Hash[l-1]*M[r-l+1] + 1ll*base*base) % base;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("J.inp", "r", stdin);
    freopen("J.out", "w", stdout);
    #endif

    M[1] = 2802;
    FOR(i,2,MAXN) M[i] = 1ll*M[i-1]*M[1] % base;
    cin>> n >> q;
    FOR(i,0,n) {
        char ch;
        cin>> ch;
        jump[i] = ch;
    }

    while(q--) {
        int ans;
        cin>> ans;
        if (ans == 1) {
            cin>> s[m]; len[m] = s[m].size();
            //build(Hash, m ,len[m]);
            FORE(i,0,25) {
                if (i)
                    FOR(j,0,len[m]) s[m][j] = jump[s[m][j] - 'A'];
                build(Hash, m, len[m]);
                int rep1 = (rep + i)%n;
                //if (rep1 == 1) cout<< s[m] <<endl;
                FORE(j,1,len[m])
                {
                    S[rep1].insert(Hash[j]);
                    //if (rep1 == 1) cout<< Hash[j] <<endl;
                }
            }
        }

        if (ans == 2) {
            rep = (rep + 1) % n;
        }

        if (ans == 3) {
            cin>> s[0]; len[0] = s[0].size();
            build(Hash, 0, len[0]);
            //cout<< Hash[ len[0] ] <<endl;
            if (S[rep].find(Hash[ len[0] ]) != S[rep].end()) {
                cout<< "YES" <<endl;
            }
            else {
                cout<< "NO" <<endl;
            }
        }
    }

    return 0;
}
