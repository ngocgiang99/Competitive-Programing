#include <bits/stdc++.h>
#include <windows.h>
#include <dos.h>
using namespace std;

#define endl '\n'

string namefile = "signature";
const string linktestfolder = "";

const int TESTS = 100;
const int MAXN = 1001;

int m, n, q;
int a[MAXN][MAXN];

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

string toString(int x) {
    string s = "";

    //cout<< '0' + s<<endl;
    while(x) {
        char ch = '0' + x%10;
        s = ch + s;
        x /= 10;
    }

    return s;
}

void delay(int x) {
    int t = 0;
    for (int i = 0; i < x*10000; ++i) t += 1;
}

int check() {
    system((namefile + ".exe").c_str());
    freopen((namefile + ".out").c_str(), "r", stdin);
    string s;
    cin>> s;
    if (s == "YES") return 1;
    return 0;
}

void createInput(int minM, int maxM, int minN, int maxN, int result) {
    int cnt = 1;
    while(true) {
        ofstream fo((namefile + ".inp").c_str());

        int m = Rand(minM, maxM);
        int n = Rand(minN, maxN);
        fo << m <<' '<< n <<endl;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x = Rand(1, 15);
                if (result == 1)
                if (i == 1 || i == m || j == 1 || j == n) x = 5;

                if (x <= 1) {
                    fo<< '*';
                }
                else fo<< "#";
            }
            fo<< endl;
        }
        fo.close();
        cout<< cnt++ << ' '<< check() << ' '<< result<<endl;
        //delay(1000);
        if (check() == result) return;
    }
}

void runAndcopyFile(int iTest) {
    system((namefile + ".exe").c_str());
    string linktest = namefile + "\\test" + toString(iTest);
    string fileCopy1 = namefile + ".inp";
    string fileCopy2 = namefile + ".out";
    CreateDirectory(linktest.c_str(), NULL);
    CopyFile(fileCopy1.c_str(),
             string(linktest + "\\" + fileCopy1).c_str(),
             TRUE);
    CopyFile(fileCopy2.c_str(),
             string(linktest + "\\" + fileCopy2).c_str(),
             TRUE);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand(time(NULL));
    CreateDirectory((namefile + "\\").c_str(), NULL);

    int ok = 0;
    for (int iTest = 1; iTest <= TESTS; ++iTest) {
        if (iTest <= 30) {
            createInput(5, 10, 5, 10, ok);
        }
        else if (iTest <= 60) {
            createInput(50, 100, 50, 100, ok);
        }
        else {
            createInput(700, 1000, 700, 1000, ok);
        }
        ok = 1 - ok;
        runAndcopyFile(iTest);
        cout<< "Created Test " << iTest <<endl;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
