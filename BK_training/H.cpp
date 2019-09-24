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

typedef pair<int, int> ii;
int a, b, c;
int t;


int process() {
    queue<ii> q;
    map<ii, int> ma;
    ma[ii(0, 0)] = 0;
    q.push(ii(0, 0));
    while(q.size()) {
        ii u = q.front(); q.pop();
        //cout<< u.fi <<' '<< u.se <<' '<< ma[u] <<endl;
        if (u.fi == c || u.se == c) return ma[u];

        if (u.fi != a) {
            ii v = u;
            v.fi = a;
            if (ma.find(v) == ma.end()) {
                ma[v] = ma[u] + 1;
                q.push(v);
            }
            v = u;
            int x = min(a - v.fi, v.se);
            v.fi += x;
            v.se -= x;
            if (ma.find(v) == ma.end()) {
                ma[v] = ma[u] + 1;
                q.push(v);
            }
        }
        if (u.se != b) {
            ii v = u;
            v.se = b;
            if (ma.find(v) == ma.end()) {
                ma[v] = ma[u] + 1;
                q.push(v);
            }
            v = u;
            int x = min(b - v.se, v.fi);
            v.se += x;
            v.fi -= x;
            if (ma.find(v) == ma.end()) {
                ma[v] = ma[u] + 1;
                q.push(v);
            }
        }
        if (u.fi) {
            ii v = u;
            v.fi = 0;
            if (ma.find(v) == ma.end()) {
                ma[v] = ma[u] + 1;
                q.push(v);
            }
        }
        if (u.se) {
            ii v = u;
            v.se = 0;
            if (ma.find(v) == ma.end()) {
                ma[v] = ma[u] + 1;
                q.push(v);
            }
        }
    }
}

int process1(int a, int b, int c) {
    int ans = 0;
    int ga = 0, gb = 0;
    int gcdAB = __gcd(a, b);
    if (c%gcdAB) return 1e9;
    if (b < c) return 1e9;
    while(true) {
        ans += 1;
        gb = b;
        if (ga > 0) {
            int x = a - ga;
            ans += 2;
            gb -= x;
            ga = 0;
        }
        if ((gb - c) % a == 0) {
            ans = ans + 2*(gb - c) / a - 1;
            return ans;
        }
        
        int k = gb / a;
        ans += 2*k; 
        ++ans;
        ga = gb%a;
        gb = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> t;
    while(t--) {
        cin>> a >> b >> c;
        if (a < c && b < c) {
            cout<< -1 <<endl;
        }
        else {
            //int x1 = process1(a, b, c);
            //int x2 = process1(b, a, c);
            //if (x1 == 1e9 && x2 == 1e9) cout<< -1 <<endl;
            //else
            //cout<< min(x1, x2) <<endl;
            if (a > b) swap(a, b);
            int x = process1(a, b, c);
            if (x == 1e9) cout<< -1 <<endl;
            else cout<< x <<endl;
            // cout<< process() <<endl;
        }
    }

    return 0;
}