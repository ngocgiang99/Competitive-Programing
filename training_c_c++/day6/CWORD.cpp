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



const int MAXN = 1e5 * 5;
const int base = 1e9 + 7;
const int N = 5000;
typedef pair<int, int> ii;

int n;
int checked[N], cnt[N];
string a[N];
vector<vector<string> > vStr;
priority_queue<ii> h;

int sameStr(string a, string b) {
    if (a.size() != b.size()) return 0;
    int len = a.size();
    FOR(i, 0, len)
    if (a[i] == '*' || b[i] == '*') continue;
    else if (a[i] != b[i]) return 0;
    return 1;
}

int good(string a, vector<string> v) {
    FOR(k, 0, v.size())
    if (!sameStr(a, v[k])) return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("CWORD.inp", "r", stdin);
    freopen("CWORD.out", "w", stdout);
    #endif
    cin>> n;
    FORE(i,1,n) cin>> a[i];
    FORE(i,1,n) 
    if (!checked[i] ){
        int ok = 1;
        FOR(j, 0, vStr.size()) 
        if (good(a[i], vStr[j])) {
            ok = 0;
            break;
        }
        if (ok) vStr.push_back(vector<string> {a[i]}), checked[i] = 1;
    }

    FORE(i,1,n)
    if (!checked[i]) {
        cnt[i] = 0;
        FOR(j, 0, vStr.size())
        if (sameStr(a[i], vStr[j][0])) ++cnt[i], cout << j << " ";
        cout <<endl;
        cout<< i <<' '<< cnt[i] <<endl;
        h.push(ii(-cnt[i], i));
    }
    //cout<< vStr.size() <<endl;
    // FOR(i, 0, vStr.size()) {
    //     FOR(j,0, vStr[i].size()) cout<< vStr[i][j] <<endl;
    //     cout<< i <<endl;
    // }

    while(h.size()) {
        int u = h.top().se;
        int cu = -h.top().fi;
        h.pop();
        if (cu != cnt[u]) continue;
        if (checked[u]) continue;

        //cout<< u <<' '<< cu <<endl;
        cnt[u] = -1;
        checked[u] = 1;
        int i = -1;
        FOR(j, 0, vStr.size()) 
        if (good(a[u], vStr[j])) {
            i = j;
            break;
        }
        cout<< u <<' '<< i <<' '<< cu <<endl;

        if (i == -1) {
            vStr.push_back(vector<string> {a[u]});
            // i = vStr.size() - 1;
            FORE(k, 1, n)
            if (!checked[k] && sameStr(a[k], a[u])) ++cnt[k];
        }
        else {
            FORE(k, 1, n)
            if (!checked[k] && good(a[k], vStr[i]) && !sameStr(a[k], a[u])) --cnt[k];
            vStr[i].push_back(a[u]);
        }
        FORE(k, 1, n)
        if (!checked[k]) h.push(ii(-cnt[k], k));
    }
    
    // FOR(i, 0, vStr.size()) {
    //     FOR(j,0, vStr[i].size()) cout<< vStr[i][j] <<endl;
    //     cout<< i <<endl;
    // }
    cout<< vStr.size() <<endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}