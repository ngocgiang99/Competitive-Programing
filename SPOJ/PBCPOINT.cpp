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
const int N = 2000 + 10;

int n, ans;
int minCol[N], minRow[N], maxCol[N], maxRow[N];
int a[N][N];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> n;
    FORE(i,0, 2000) {
        minCol[i] = minRow[i] = 1e5;
        maxCol[i] = maxRow[i] = -1e5;
    }

    FORE(i,1,n) {
        int x, y;
        cin>> x >> y;
        x += 1000;
        y += 1000;
        ++a[x][y];
        minRow[y] = min(minRow[y], x);
        maxRow[y] = max(maxRow[y], x);
        minCol[x] = min(minCol[x], y);
        maxCol[x] = max(maxCol[x], y);
    }


    FORE(t, 1, 5) {
        FORE(i,0, 2000) {
            FORE(j, minCol[i], maxCol[i]) {
                a[i][j] = 1;
                minRow[j] = min(minRow[j], i);
                maxRow[j] = max(maxRow[j], i);
            }
        }

        FORE(j,0, 2000) {
            FORE(i, minRow[j], maxRow[j]) {
                a[i][j] = 1;
                minCol[i] = min(minCol[i], j);
                maxCol[i] = max(maxCol[i], j);
            }
        }
    }

    FORE(i,0, 2000)
    FORE(j,0, 2000)
    ans += a[i][j];

    cout<< ans <<endl;



    return 0;
}