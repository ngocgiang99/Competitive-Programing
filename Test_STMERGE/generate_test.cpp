#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

#define endl '\n'

const string namefile = "STMERGE";
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

    //system((NAME + ".exe").c_str());
    //system((NAME + "_trau.exe").c_str());

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

void createInput(int ql, int qh, int ml, int mh, int nl, int nh) {
    ofstream fo((namefile + ".inp").c_str());

    q = Rand(ql, qh);
    fo<< q <<endl;

    while(q--) {
        m = Rand(ml, mh);
        n = Rand(nl, nh);
        fo<< m <<' '<< n <<endl;

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                int x = Rand(1, 1e9);
                fo<< x <<' ';
            }
            fo<< endl;
        }
    }

    fo.close();
}

void runAndcopyFile(int iTest) {
    system((namefile + ".exe").c_str());
    string linktest = "TEST\\test" + toString(iTest);
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
    CreateDirectory("TEST\\", NULL);

    for (int iTest = 1; iTest <= TESTS; ++iTest) {
        if (iTest <= 60) {
            createInput(1, 10, 1, 10, 1, 10);
        }
        else if (iTest <= 90) {
            createInput(1, 3, 100, 500, 100, 500);
        }
        else if (iTest <= 97) {
            createInput(6, 10, 200, 300, 200, 300);
        }
        else if (iTest <= 99) {
            createInput(1, 2, 500, 1000, 500, 1000);
        }
        else {
            createInput(1, 1, 1000, 1000, 1000, 1000);
        }
        runAndcopyFile(iTest);
        cout<< "Created Test " << iTest <<endl;
    }



    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
