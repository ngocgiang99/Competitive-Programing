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
typdef pair<int, int> ii;

struct TrieNode {
    int p;
    int h;
    int cnt;

    TrieNode () {
        this.a[0] = 0;
        this.a[1] = 0;
    }
} root = TrieNode();

struct Trie {
    vector<TrieNode> nodes;
    int cnt = 0;

    void insert(string s) {
        TrieNode cur = root;
        for (int i = 0; i < s.size(); ++i) 
        if (cur.a[s[i] - '0'] == 0) {
            nodes.push_back(TrieNode());
            cur.a[s[i] - '0'] = ++cnt;
            
            
            nodes[cnt].cnt += cur.cnt;
            cur = nodes.back();

        }
        else {
            cur = nodes[cur.a[s[i] - '0']];
        }
    }
} trie;


void preprocess() {
    trie.nodes.push_back(root);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    preprocess();
    cin>> n;
    FORE(i,1,n) {
        int q; string s;
        cin>> q >> s;
        if (q == 0) {
            trie.insert(s);
        }
    }



    return 0;
}