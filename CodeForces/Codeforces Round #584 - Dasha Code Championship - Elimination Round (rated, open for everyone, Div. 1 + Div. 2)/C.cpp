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
const int N = 500;
typedef pair<int, int> ii;

int n;
int pos[MAXN];
char ch[MAXN];
vector<int> v[N];
ii a[MAXN];

void process() {
    pos[1] = 1;
    int last = ch[1] - '0';
    int fi = 0;
    FORE(i,0,9) v[i].clear();
    v[ch[1] - '0'].pb(1);

    FORE(i,2,n)
    if (ch[i] - '0' < last) {
        FORE(j, ch[i] - '0' + 1, 9) {
            FOR(k, 0, v[j].size()) {
                int id = v[j][k];
                if (fi == 0) fi = ch[id] - '0';
                pos[id] = 2;
            }
            v[j].clear();
        }
        pos[i] = 1;
        v[ch[i] - '0'].pb(i);
        last = ch[i] - '0';
    }
    else {
        if (fi && ch[i] - '0' > fi) {
            pos[i] = 2;
            continue;
        }
        v[ch[i] - '0'].pb(i);
        pos[i] = 1, last = ch[i] - '0';
    }
    last = 0;
    string s;
    FORE(i,1,n) s += '0';
    FORE(i,1,n)
    if (pos[i] == 1)
    if (ch[i] - '0' < last) {
        cout<< "-" <<endl;
        return;
    }
    else last = ch[i] - '0';

    FORE(i,1,n)
    if (pos[i] == 2)
    if (ch[i] - '0' < last) {
        cout<< "-" <<endl;
        return;
    }
    else last = ch[i] - '0';

    FORE(i,1,n)
    cout<< pos[i];
    cout<<endl;
}

void process1() {
    FORE(i,1,n) a[i] = ii(ch[i] - '0', i);

    sort(a+1, a+n+1);
    FORE(i,1,n)
    cout<< a[i].se <<' ';
    cout<<endl;

    int cnt = 0;
    FORE(i,2,n)
    if (a[i].se < a[i-1].se) ++cnt;
    if (cnt > 1) {
        cout<< '-' <<endl;
        return;
    }
    

    cnt = 1;
    pos[a[1].se] = 1;
    FORE(i,2,n)
    if (a[i].se < a[i-1].se) {
        ++cnt;
        pos[a[i].se] = cnt;
    }
    else pos[a[i].se] = cnt;
    FORE(i,1,n)
    cout<<pos[i];
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
    #endif
    int T;
    cin>> T;
    while(T--) {
        cin>> n;
        cin>> ch+1;
        // process();
        process();
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}