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

int n, m;
int a[MAXN], c[MAXN], id[MAXN];
vector<int> arr[MAXN];
priority_queue<int> h;
long long ans;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>> n >> m;
    FORE(i,1,n) {
        cin>> a[i];
        arr[a[i] % m].pb(i);
    }

    int k = n/m;
    FOR(i,0,m) c[i] = arr[i].size(), id[i] = c[i] - 1;

    FOR(i,0,m) {
        if (c[i] > k) {
            h.push(i);
        }

        while(c[i] < k) {
            while(h.size()) {
                int u = h.top(); h.pop();
                ++c[i];
                --c[u];
                a[arr[u][id[u]--]] += (i - u);
                //cout<< a[arr[u][id[u]+1]] <<' '<< arr[u][id[u]+1] <<endl;
                ans += (i - u);
                //arr[u].erase(arr[u].begin() + arr[u].size() - 1);
                if (c[u] > k) h.push(u);
                if (c[i] == k) break;
            }
            if (!h.size()) break;
        }

    }
    //return 0;

    FOR(i,0,m) {
        if (c[i] > k) {
            h.push(i);
        }

        while(c[i] < k) {
            while(h.size()) {
                int u = h.top(); h.pop();
                ++c[i];
                --c[u];
                a[arr[u][id[u]--]] += (m + (i - u));
                ans += (m + (i - u));
                if (c[u] > k) h.push(u);
                if (c[i] == k) break;
            }
            if (!h.size()) break;
        }
    }

    cout<< ans <<endl;
    FORE(i,1,n)
    cout<< a[i] <<' ';
    return 0;
}