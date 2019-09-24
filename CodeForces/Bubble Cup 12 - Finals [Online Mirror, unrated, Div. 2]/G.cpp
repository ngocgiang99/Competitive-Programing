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



const int MAXN = 1e5 + 5;
const int base = 1e9 + 7;
const int N = 500;

int m, n;
int c[MAXN], a[MAXN];
long long ans;
long long sumCol[MAXN], sumRow[MAXN], d[MAXN];
priority_queue<long long> h;


void prepare() {
    FOR(i, 0, m) sumRow[i+1] = 0;
    FOR(j, 0, n) sumCol[j+1] = 0;

    FOR(i, 0, m)
    FOR(j, 0, n) {
        sumCol[j+1] = sumCol[j+1] + a[i * n + j];
        sumRow[i+1] = sumRow[i+1] + a[i * n + j];
    }
}

void process(int t) {

    if (t == 0) {
        long long sum = 0;
        long long tmp = 0;
        FOR(j, 0, n)
        d[j] = sumCol[j+1];
        sort(d, d+n);
        FORE(j, 1, 4)
        if (n - j >= 0) tmp = tmp + d[n-j];

        ans = max(ans, tmp);
        
        tmp = 0;
        FOR(i, 0, m)
        d[i] = sumRow[i+1];
        sort(d, d+m);
        FORE(j, 1, 4)
        if (n - j >= 0) tmp = tmp + d[m-j];

        ans = max(ans, tmp);
    }
    else if (t == 1) {
        long long sum = 0;
        FOR(i, 0, m) {
            long long tmp = sumRow[i+1];
            
            FOR(j, 0, n)
            d[j] = sumCol[j+1] - a[i * n + j];
            sort(d, d+n);
            FORE(j, 1, 3)
            if (n - j >= 0) tmp = tmp + d[n-j];

            sum = max(sum, tmp);
        }   
        ans = max(ans, sum);
    }
    else if (t == 2) {
        long long sum = 0;
        
        FOR(i1, 0, m) {
            long long mx1 = 0, mx2 = 0;
            FOR(j, 0, n)
            if (sumCol[j+1] - a[i1 * n + j] > mx1) {
                mx2 = mx1;
                mx1 = sumCol[j+1] - a[i1 * n + j];
            }
            else if (sumCol[j+1] - a[i1 * n + j] > mx2) {
                mx2 = sumCol[j+1] - a[i1 * n + j];
            }

            FOR(i2, i1+1, m) {
                long long tmp = sumRow[i1+1] + sumRow[i2+1];
                if (tmp + mx1 + mx2 <= ans) continue;

                FOR(j, 0, n) 
                d[j] = sumCol[j+1] - a[i1 * n + j] - a[i2 * n + j];
                sort(d, d+n);
                FORE(j, 1, 2)
                if (n - j >= 0) tmp = tmp + d[n-j];
                
                sum = max(sum, tmp);
            }
        }
        ans = max(ans, sum);
    }
    else {
        long long sum = 0;
        FOR(j, 0, n) {
            long long tmp = sumCol[j+1];
            
            FOR(i, 0, m)
            d[i] = sumRow[i+1] - a[i * n + j];
            sort(d, d+m);
            FORE(i, 1, 3)
            if (n - i >= 0) tmp = tmp + d[n-i];

            sum = max(sum, tmp);
        }   
        ans = max(ans, sum);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    read(m); read(n);
    FOR(i,0,m)
    FOR(j,0,n) {
        read(a[i * n + j]);
    }

    if (m > n) {
        int mNew = n, nNew = m;
        FOR(i, 0, m)
        FOR(j, 0, n)
        c[j * nNew + i] = a[i * n + j];
        swap(m, n);
        FOR(i, 0, m)
        FOR(j, 0, n)
        a[i * n + j] = c[i * n + j];
    }
    
    prepare();
    FORE(t, 0, 3) 
    process(t);

    cout<< ans <<endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}