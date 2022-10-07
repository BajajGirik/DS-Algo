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

// 5  1
// 10 1
// 15 1
// 20 1
// 25 2
// 30 1
// 35 1
// 40 1
// 45 1
// 50 2
// 55 1
// 60 1
// 65 1
// 70 1
// 75 2
// 80 1
// 85 1
// 90 1
// 95 1
// 100 2
// 105 1
// 110 1
// 115 1
// 120 1
// 125 3
// 130 1
// 135 1
// 140 1
// 145 1
// 150 2

void solve() {
	long n;
	cin >> n;
	long sum = 0;
	for(long i = 5; n / i >= 1; i *= 5) {
		sum += n / i;
	}
	cout << sum << endl;
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