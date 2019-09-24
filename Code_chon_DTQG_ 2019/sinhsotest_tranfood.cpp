#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "tranfood";
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

int a[100050];

int main()
{
    srand(time(NULL));
    for(int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());

        int n = Rand(100,1000);
        inp<< n <<endl;

        for(int i = 1; i <= n; ++i) a[i] = i;

        int op = Rand(1,1e5);
        for(int i = 1; i <= op; ++i) {
            int u = Rand(1,n);
            int v = Rand(1,n);

            while(u == v) u = Rand(1,n) , v = Rand(1,n);

            swap(a[u], a[v]);
        }

        for(int i = 1; i < n; ++i) {
            int j = Rand(1,i);
            int d = Rand(1,1e4);
            inp<< a[i+1] <<' '<< a[j] <<' '<< d <<endl;
        }
        for(int i = 1; i <= n; ++i) inp<< Rand(1,1e4) <<' ';

        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());
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
