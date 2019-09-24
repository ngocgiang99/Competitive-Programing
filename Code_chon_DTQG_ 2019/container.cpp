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

int n, m , w;
int it[MAXN], Left[MAXN], Right[MAXN], Leaf[MAXN];


void build(int x, int l, int r) {
    Left[x] = l;
    Right[x] = r;

    if (l == r) {
        Leaf[l] = x;
        it[x] = w;

        return ;
    }

    int mid = (l + r) >> 1;

    build(2*x, l, mid);
    build(2*x + 1, mid+1, r);

    it[x] = w;
}

int get(int x, int l, int r) {
    if (Left[x] > r || Right[x] < l) return -1;
    if (l <= Left[x] && Right[x] <= r) return it[x];

    return max(get(2*x, l, r), get(2*x+1, l, r));
}

void update(int x, int value) {
    x = Leaf[x];
    it[x] += value;
    //cout<< x <<' '<< it[x] <<endl;

    while(x > 1) {
        x >>= 1;
        it[x] = max(it[2*x], it[2*x+1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("container.inp", "r", stdin);
    freopen("container.out", "w", stdout);
    #endif
    cin>> m >> w >> n;

    build(1, 1, m);

    FORE(i,1,n) {
        int x;
        cin>> x;

        int lef = 1, rig = n, ans = 0;
        while(lef <= rig) {
            int mid = (lef + rig) >> 1;

            //cout<< mid <<' '<< get(1,1,mid) <<endl;
            if (get(1,1,mid) >= x) {
                ans = mid;
                rig = mid - 1;
            }
            else
                lef = mid + 1;
        }

        if (ans) {
            cout<< ans <<endl;
            update(ans, -x);
        }
        else
            cout<< -1 <<endl;
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
