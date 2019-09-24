/*input
7
1 5 1 7 3 1 3
17
17
-1 0 1 2 3 4 5
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <functional>
#include <math.h>
#include <string.h>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <stdlib.h>
#include <list>
#include <assert.h>
#include <time.h>
#include <fstream>
#include <sstream>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define N 100005
#define int long long
void verify(bool x, string s = "Wrong answer") {
	if (x == false) {
		cout << s << endl << "0.0" << endl;
		exit(0);
	}
}
void OK() {
	cout << "Ok, right answer\n1.0";
	exit(0);
}
const string name = "sequence";
const string inp = ".inp", out = ".out", sol = ".out"; 

struct data {
	int ans = -1;
	vector<int> order;
} con, ans;

ostream& operator << (ostream &os, vector<int>&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << sp;
	return os;
}
ostream& operator << (ostream &os, pair<int, int> x) {
	cout << x.fi << sp << x.se << sp;
	return os;
}
ostream& operator << (ostream &os, vector<pair<int, int> >&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << endl;
	return os;
}

int n;
vector<int> a;
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string inFolder, outFolder;
	getline(cin, inFolder);
	getline(cin, outFolder);
	string inFile = inFolder + name + inp, outFile = outFolder + name + out, ansFile = inFolder + name + sol;
	ifstream fin(inFile.c_str()), fout(outFile.c_str()), fans(ansFile.c_str()); // change all cin to this
	fin >> n;
	for (int i = 0; i < n; i++) {
		int t; fin >> t;
		a.push_back(t);
	}
	fans >> ans.ans;
	fout >> con.ans;
	for (int i = 0; i < n; i++) {
		int t = -1e9; fout >> t;
		con.order.push_back(t);
	}
	int cnt = 0;
	if (ans.ans == con.ans) cnt++;
	for (int i = 0; i < n; i++) {
		ans.ans -= abs(con.order[i] - a[i]);
	}
	if (ans.ans == 0) {
		vector<int> x = con.order;
		sort(x.begin(), x.end());
		if (x == con.order) cnt++;
	}
	if (cnt == 0) cout << "Wrong answer 0.0" << endl << "0.0" << endl;
	else if (cnt == 1)cout << "Wrong answer 0.5" << endl << "0.5" << endl;
	else cout << "Ok, correct result" << endl << "1.0" << endl;
}