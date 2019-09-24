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

int n, k, t;
int a[MAXN];
deque<int> dq;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    read(t);
    FORE(Test,1,t) {
        read(n); read(k);
        FORE(i,1,n) read(a[i]);
        sort(a+1, a+n+1);
        a[0] = - base;

        int ans =  0;
        int pre = a[0];
        while(dq.size()) dq.pop_front();
        FORE(i,1,n) 
        if (a[i] - dq.front() > k) {
            //cout<< dq.front() <<endl;
            dq.pop_front();
            dq.push_back(a[i]);
        }
        else {
            ++ans;
            dq.push_back(a[i]);
        }

        cout<< "Case #" << Test <<endl;
        cout<< ans <<endl;
    }



    return 0;
}