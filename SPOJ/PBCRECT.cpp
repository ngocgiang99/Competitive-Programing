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

int m, n;
int h[20000], cnt[20000], sign[20000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> m >> n;
    //FORE(i,1,m)
    //FORE(j,1,n) cin>> a[i][j];
    int ans = 0, ansSwap = 1e9, idSwap = 1e5;

    FORE(i,1,m) {
        FORE(j,1,n) {
            char ch;
            cin>> ch;
            h[j] = (ch == '1') ? h[j] + 1 : 0;
            if (sign[h[j]] != i) {
                sign[h[j]] = i;
                cnt[h[j]] = 1;
            }
            else ++cnt[h[j]];
            //cout<< i <<' '<< j <<' '<< h[j] <<endl;
        }

        int kx = -1;
        int res = 0;
        FORE(j,1,n) {
            if (cnt[j] * j > res) {
                res = cnt[j] * j;
                kx = j;
            }
            else if (cnt[j] * j == res){
                if (kx > j) {
                    kx = j;
                }
            }
        }
        if (kx != -1 && res >= ans) {
            int tmp = 0;
            int mxTmp = 0;
            FORE(j,1,n)
            if (h[j] >= kx) ++tmp;
            else {
                mxTmp = max(mxTmp, tmp);
                tmp = 0;
            }
            mxTmp = max(mxTmp, tmp);
            //cout<< i <<' '<< kx <<' '<< cnt[kx] <<' '<< mxTmp <<' '<< ansSwap <<endl;
            if (res > ans) {
                ans = res;
                ansSwap = cnt[kx] - mxTmp;
                idSwap = kx;
            }
            else {
                if (cnt[kx] - mxTmp < ansSwap) {
                    ansSwap = cnt[kx] - mxTmp;
                }
            }
            
        }
    }

    cout<< ans <<endl;
    cout<< ansSwap <<endl;

    return 0;
}