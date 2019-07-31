#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "D";
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
        inp<< fixed << setprecision(2);
        int n = Rand(5,15);
        inp<< n <<endl;
        for(int i = 1; i <= n; ++i) {
            double u = 1.0*Rand(1,1000) / 100;
            inp<< u <<' ';
        }
        inp<<endl;
        int q = Rand(1,15);
        inp<< q <<endl;
        while(q--) {
            int ans = Rand(1,2);
            if (ans == 1) {
                int i = Rand(1,n);
                double u = 1.0*Rand(1,1000) / 100;
                inp<< ans <<' '<< i <<' '<< u <<endl;
            }
            else {
                int l = Rand(1,n);
                int r = l + Rand(1,n-l+1);
                inp<< ans <<' '<< l <<' '<< r <<endl;
            }
        }
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
