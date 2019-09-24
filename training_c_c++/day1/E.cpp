#include <bits/stdc++.h>

using namespace std;
typedef pair<char, int> pci;
const int MAXN = 1e6 + 10;
int n;
int f[MAXN];
char a[MAXN];
stack<pci> st;

int main() {
    cin>> a+1; n = strlen(a+1);

    int tmp = 500000;
    long long ans = 0;
    st.push(pci(' ', 0));
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == '(') st.push(pci(')', i)), f[i] = 1;
        if (a[i] == '[') st.push(pci(']', i)), f[i] = 1;
        if (a[i] == '{') st.push(pci('}', i)), f[i] = 1;
        if (a[i] == ')' || a[i] == ']' || a[i] == '}') {
        if (st.size() == 0 || st.top().first != a[i]) {
                while(st.size()) st.pop();
                st.push(pci(' ', 0));
                f[0] = 1;
                continue;
            }
            st.pop();
            ans += f[st.top().second];
            ++f[st.top().second];
        }
        //cout<< i <<' '<< ans <<endl;
    }

    cout<< ans <<endl;
    return 0;
}