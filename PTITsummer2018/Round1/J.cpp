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

int t, a, b;
int Prime[N], level[N];

void sangnt() {
    int N_sqrt = sqrt(N);
    FORE(i,2,N_sqrt)
    if (!Prime[i])
        for(int j = i*i; j < N; j += i) Prime[j] = i;

    FOR(i,2,N)
    if (!Prime[i]) Prime[i] = i; 
}

void process(int x) {
    while(x > 1) {
        ++level[Prime[x]];
        x /= Prime[x];
    }
}

void init() {
    cin>> a >> b;

    FORE(i,1,b) level[i] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    sangnt();
    cin>> t;
    while(t--) {
        init();

        FORE(i,a+1,b)
        process(i);

        long long ans = 1;
        FORE(i,1,b)
        ans *= (level[i] + 1);

        cout<< ans <<endl;
    } 


    return 0;
}