#include <bits/stdc++.h>
using namespace std;
#define FORE(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
// Tên chương trình
const string NAME = "E"; 
// Số test kiểm tra
const int NTEST = 10000000;

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

int main()
{
    srand(time(NULL));
    for(int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        int n = 100;
        inp<< n <<endl;
        FORE(i,1,n) {
            int len = Rand(1, 10);
            //len = 10;
            FORE(j,1,len) {
                int x = Rand(1, 3);
                if (x == 1) {
                    char a = '0' + Rand(0, 9);
                    inp<< a;
                }
                if (x == 2) {
                    char a = 'a' + Rand(0, 25);
                    inp<< a;
                }
                if (x == 3) {
                    char a = 'A' + Rand(0, 25);
                    inp<< a;
                }
            }
            inp<< " ";
        }
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system((NAME + ".exe").c_str());
        system((NAME + "_test.exe").c_str());
        // Nếu dùng linux thì thay fc bằng diff
        if(system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}