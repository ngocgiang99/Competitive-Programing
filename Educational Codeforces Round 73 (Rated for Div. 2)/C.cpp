#include <bits/stdc++.h>

using namespace std;

int q;
int a, b, c;

int main() {
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin>> a >> b >> c;
        int x = min(a, b);
        a -= x;
        b -= x;
        c = c + a + b;
        int g = x - c;
        if (g > 0) {
            g = g / 3 + (g%3 != 0);
            c += 2*g;
            x -= g;
        }
        cerr << x <<" " << c <<endl;
        cout << min(x, c) <<endl;
    }
}