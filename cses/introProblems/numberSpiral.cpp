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
	long long x, y, finalVal;
	bool rem;
	cin >> x >> y;
	if(x >= y) {
		y--;
		rem = x & 1;
		x = rem ? (x-1) : x;
		finalVal = x * x;
		finalVal = rem ? (finalVal + 1) : finalVal;
		finalVal = rem ? (finalVal + y) : (finalVal - y);
		cout << finalVal << endl;
		return;
	}

	x--;
	rem = y & 1;
	y = rem ? y : (y-1);
	finalVal = y * y;
	finalVal = rem ? finalVal : (finalVal + 1);
	finalVal = rem ? (finalVal - x) : (finalVal + x);
	cout << finalVal << endl;
}

int main () {
	clock_t start = clock();
	file_i_o();
	int T=1;
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