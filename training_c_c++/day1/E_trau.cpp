#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;


int n;
char a[MAXN];


int main() {
    cin>> a+1; n = strlen(a+1);

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        stack<char> st;
        //cout<< i << ' ' << st.size() <<endl;
        for (int j = i; j <= n; ++j) {
            if (a[j] == '(') ++cnt1, st.push(')');
            if (a[j] == '[') ++cnt2, st.push(']');
            if (a[j] == '{') ++cnt3, st.push('}');
            //if (st.size()) cout<< i <<' '<< j <<' '<< st.top() <<endl;
            if (a[j] == ')' || a[j] == ']' || a[j] == '}') {
                if (st.size() == 0 || st.top() != a[j]) break;
                if (a[j] == ')') --cnt1;
                if (a[j] == ']') --cnt2;
                if (a[j] == '}') --cnt3;
                st.pop();
            }
            //cout<< i <<' '<< j <<' '<< cnt1 << ' ' << cnt2 << ' '<< cnt3 <<endl;
            if (cnt1 < 0 || cnt2 < 0 || cnt3 < 0) break;
            if (cnt1 == 0 && cnt2 == 0 && cnt3 == 0) {
                
                ++ans;
                //cout<< i <<' '<< j <<' '<< ans <<endl;
            }
        }
    }

    cout<< ans <<endl;
    return 0;
}