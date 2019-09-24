#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "C";
// Số test kiểm tra
const int NTEST = 100000;

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

int a[500000], b[500000];

int main()
{
    srand(time(NULL));
    for(int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        int n = Rand(1,400);

        inp<< n <<endl;

        int x = Rand(0,1);
        if (x) {
            int k = Rand(1,1e3);
            for(int i = 1; i <= n; ++i) {
                a[i] = Rand(0,1e3);
                b[i] = a[i] % k;
            }

            for(int i = 1; i <= n; ++i)
            inp<< a[i] <<' ';
            inp<<endl;
            for(int i = 1; i <= n; ++i)
            inp<< b[i] <<' ';
        }
        else {
            for(int i = 1; i <= n; ++i)
            inp<< Rand(0,1e3) <<' ';
            inp<<endl;
            for(int i = 1; i <= n; ++i)
            inp << Rand(0,1e3) <<' ';
        }

        inp.close();

        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());

        if(system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
