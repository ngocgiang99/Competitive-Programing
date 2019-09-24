#include <bits/stdc++.h>
#include "RGAME.h"

using namespace std;

int main() {
    for (int i = 2; i <= 1000000; i += 2) {
        int n = get_n(i);
        cout << n <<endl;
        int ok = 0;
        if (n&1) {
            int x;
            while(n) {
                x = play(1);
                if (x == -1) break;
                --n;
                x = get_x(); 
                if (x == -1) break;  
                n -= x;
            }
        }
        else if (n == 2) {
            int x = 0;
            x = get_x();
            play(1);
        }
        else {
            int x = 0;
            int y = 0;
            if ((n/2)&1) play(2), n -= 2;
            while(n) {
                //cout << "abc" <<endl;
                x = get_x();
                if (x == -1) break;
                // cout << "AI played: " << x <<' '<< n << endl; 
                if (x >= n/2) y = play(n - x);
                else n -= x;
                if (y == -1) break;
                if (n&1) y = play(1), --n;
                else y = play(x), n -= x;
                if (y == -1) break;
                // cout << "I played: " << n <<endl;
            }
        }
        // system("pause");
    }
}