/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define vi                vector<ll>
#define vvi               vector<vi>
#define all(v)            v.begin(), v.end()
#define pii               pair<ll, ll>
#define pb                push_back
#define mp                make_pair
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (auto i = a; i < b; ++i)
#define looprev(i, a, b)  for (auto i = a; i >= b; --i)
#define rloop(i, a)       for (auto i : a)
#define rrloop(i, a)      for (auto &i : a)
#define mod               1'000'000'007
#define endl              '\n'
#define ff                first
#define ss                second
/******************************************************/

void file_i_o() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);
#endif
}

void printWithZeroes(string s, int totalLength) {
	int n = s.size();
	if(n >= totalLength) {
		cout << s << endl;
		return;
	}

	string extraZeros = "";
	for(int i = 0; i < (totalLength - n); ++i) {
		extraZeros += "0";
	}

	cout << extraZeros + s << endl;
}

void solve() {
	int n;
	cin >> n;
	vector<vector<string>> grayCodes = {
		{"0", "1"},
		{"11", "10"}
	};

	for(string gc: grayCodes[0]) {
		printWithZeroes(gc, n);
	}

	if(n == 1) {
		return;
	}

	for(string gc: grayCodes[1]) {
		printWithZeroes(gc, n);
	}

	for(int i = 2; i < n; ++i) {
		vector<string> grayCodesOfLengthI = {};

		string prefix = "1";
		for(int k = i-1; k >= 0; --k) {
			int size = grayCodes[k].size();
			for(int j = size - 1; j >= 0; --j) {
				string grayCode = prefix + grayCodes[k][j];
				grayCodesOfLengthI.push_back(grayCode);
				printWithZeroes(grayCode, n);
			}
			prefix += "0";
		}

		grayCodes.push_back(grayCodesOfLengthI);
	}
}

int main () {
	clock_t start = clock();
	file_i_o();
	int T=1;
	// cin >> T;
	while (T--) {
		solve();
	}
	#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
		<< " sec";
	#endif
	return 0;
}