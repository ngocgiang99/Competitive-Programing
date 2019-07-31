#include<bits/stdc++.h>
#define FOR(i, j, k) for(int i = j; i <= k; i ++)
#define FORD(i, j, k) for(int i = j; i >= k; i --)
#define mn 100005
#define maxC 1000000007
#define pb push_back
#define mp make_pair

using namespace std;
int n, cnt['z' + 1];

void setup()
{
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    char c;
    FOR(i, 0, n - 1)
    {
        cin >> c;
        cnt[c] ++;
    }
    FOR(i, 'a', 'z')
    if (cnt[i] >= 2)
    {
        cout << "Yes";
        return;
    }
    cout << (n == 1? "Yes" : "No");
}

void xuly()
{

}

int main()
{
    iostream::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    setup();
    xuly();
    return 0;
}
