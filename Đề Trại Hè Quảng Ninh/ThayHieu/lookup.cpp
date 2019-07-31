//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "lookup"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

int n, m, cnt = 0;
string s[maxn];
int Child[1000000][26], num[1000000], res[maxn];
map <string, int> M;

struct data{
    int id, pos;
    string st;
};
data a[maxn];

void Add(string st){
    int node = 0, sum = 0;
    for (char c : st){
        char ch = c - 'a';
        if (Child[node][ch] == 0) Child[node][ch] = ++cnt;
        node = Child[node][ch];
        ++num[node];
    }
}

int Get(string st){
    int node = 0, sum = 0;
    for (char c : st){
        char ch = c - 'a';
        if (Child[node][ch] == 0) break;
        node = Child[node][ch];
        sum += num[node];
    }
    return sum;
}

bool cmp( data p, data q){
    return (p.pos < q.pos);
}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        if (!M[s[i]]) M[s[i]] = i;
    }
    cin >> m;
    string st;
    for (int i = 1; i <= m; i++){
        cin >> st;
        if (M[st] != 0) a[i] = {i, M[st], st};
        else a[i] = {i, n, st};
    }
    sort(a+1, a+m+1, cmp);
    int cur = 1;
    for (int i = 1; i <= m; i++)
    {
        while (cur <= a[i].pos) Add(s[cur++]);
        res[a[i].id] = Get(a[i].st) + a[i].pos;
    }
    for (int i = 1; i <= m; i++) cout << res[i] << endl;
    return 0;
}

