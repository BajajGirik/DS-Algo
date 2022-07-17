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
	string s;
	cin >> s;

	int n = s.size();
	vi metaData;
	char prev = s[0];

	loop(i, 1, n) {
		if(s[i] != prev) {
			metaData.pb(i+1);
			prev = s[i];
		}
	}

	int m;
	cin >> m;

	int size = metaData.size();

	// loop(i, 0, size) cout << metaData[i] << " ";
	// cout << endl;
	while(m--) {
		int l, r;
		cin >> l >> r;

		int leftIndex = lower_bound(all(metaData), l) - metaData.begin();
		int rightIndex = lower_bound(all(metaData), r) - metaData.begin();
		
		int maxi = r - l;
		
		// cout << leftIndex << " " << rightIndex << ": ";

		if(leftIndex >= 0 && leftIndex < size && metaData[leftIndex] == l)
			++leftIndex;

		if(rightIndex >= 0 && rightIndex < size && metaData[rightIndex] == r)
		   --maxi;

		maxi -= rightIndex - leftIndex;

		cout << maxi << endl;
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
