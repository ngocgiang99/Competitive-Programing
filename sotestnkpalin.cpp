#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "nkpalin";
// Số test kiểm tra
const int NTEST = 100;

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
        int n = Rand(1,15);
        int k = Rand(10,101);
        int m = Rand(1,5000);

        inp<< n <<' '<< k <<' '<< m <<endl;
        for(int i = 1;  i <= n; ++i)
            inp<< Rand(0,1);

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
