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

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	vector<vector<int>> a(26, vector<int>{});

	loop(i, 0, n) {
		char key = s[i];
		int start = i;
		while(i<n-1 and s[i+1] == key) ++i;
		a[key-'a'].pb(i-start+1);
	}

	loop(i, 0, 26) sort(all(a[i]), greater<int>());

	int globalMaxi = 0, maxi[26] = {0}, index = 0;

	loop(j, 0, n+1) {
		int flag = 0;
		loop(i, 0, 26) {
			if(j<a[i].size()) maxi[i] += a[i][j];
			else ++flag;
			globalMaxi = max(globalMaxi, maxi[i]);
		}

		++index;
		cout << globalMaxi << " ";
		if(flag == 26) break;
	}

	loop(i, index, n+1) cout << globalMaxi << " ";

	cout << endl;
}

int main () {
	clock_t start = clock();
	file_i_o();
	ll T=1;
	cin >> T;
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