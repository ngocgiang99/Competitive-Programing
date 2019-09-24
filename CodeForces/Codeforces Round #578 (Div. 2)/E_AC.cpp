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
char ans[10*MAXN];
int po[2][10*MAXN];
int Mod[2] = {1000000753, 1000000447};



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("E.inp", "r", stdin);
    //freopen("E.out", "w", stdout);

    cin>> n;

    po[0][0] = 1; po[0][1] = 2208;
    po[1][0] = 1; po[1][1] = 1003;
    
    int mx = 1e6;
    FORE(x,0,1)
    FORE(i,2,mx) po[x][i] = 1ll*po[x][i-1] * po[x][1] % Mod[x]; 

    int len = 0;
    FORE(i,1,n) {
        string s;
        cin>> s;
        int t = -1;
        if (i > 1) {
            int i1 = len-1;
            int i2 = 0;
            long long h11 = 0, h12 = 0, h21 = 0, h22 = 0;
            while(i1 >= 0 && i2 < s.size()) {
                h11 = (h11 + 1ll*ans[i1]*po[0][i2]) % Mod[0];
                h12 = (h12 * po[0][1] + s[i2]) % Mod[0];
                h21 = (h21 + 1ll*ans[i1]*po[1][i2]) % Mod[1];
                h22 = (h22 * po[1][1] + s[i2]) % Mod[1];
                
                if (h11 == h12 && h21 == h22) t = i2;
                //cout<< h11 <<' '<< h12 <<' '<< h21 <<' '<< h22 <<' '<< t <<endl;
                --i1;
                ++i2;
            }
        }
        //cout<< i <<' '<< t <<endl;

        FOR(j, t+1, s.size())
        ans[len++] = s[j];
    }

    FOR(i, 0, len)
    cout<< ans[i];



    return 0;
}