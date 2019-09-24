#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 50;

int n;
int a[MAXN], b[MAXN];
long long f[MAXN][3];

void init() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin>> a[i] >> b[i];
}

void process() {
    for (int i = 1; i <= n; ++i) f[i][0] = f[i][1] = f[i][2] = 1e17;

    for (int i = 1; i <= n; ++i) {
        for (int x = 0; x <= 2; ++x)
        for (int xx = 0; xx <= 2; ++xx)
        if (a[i-1] + xx != a[i] + x) {
            f[i][x] = min(f[i][x], f[i-1][xx] + 1ll * b[i] * x);
        }
    }

    long long ans = min(f[n][0], f[n][1]);
    ans = min(ans, f[n][2]);
    cerr << "answer:\n";
    cout << ans <<endl;
}

int main() {
    int q;
    cin>> q;
    while(q--) {
        init();
        process();
    }
}