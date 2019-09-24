#include <iostream>

using namespace std;

int main() {
    int n;
    cin>> n;
    long long ans = -1e17, res = -1e17;
    for (int i = 0; i < n; ++i) {
        int a;
        cin>> a;
        res = max(1ll*a, res + a);
        ans = max(ans, res);
    }
    cout<< ans <<endl;

    return 0;
}