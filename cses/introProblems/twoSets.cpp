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
	long n;
	cin >> n;
	if(n % 4 == 0) {
		cout << "YES" << endl;
		cout << n / 2 << endl;
		for(long i = 1; i <= n; i += 4) {
			cout << i << " ";
			cout << i + 3 << " ";
		}

		cout << endl << n / 2 << endl;
		for(long i = 2; i <= n; i += 4) {
			cout << i << " ";
			cout << i + 1 << " ";
		}
	} else if(n-3 >= 0 && (n - 3) % 4 == 0) {
		cout << "YES" << endl;
		cout << n/2 + 1 << endl;
		cout << "1 2 ";
		for(long i = 4; i <= n; i += 4) {
			cout << i << " ";
			cout << i + 3 << " ";
		}

		cout << endl << n / 2 << endl;
		cout << "3 ";
		for(long i = 5; i <= n; i += 4) {
			cout << i << " ";
			cout << i + 1 << " ";
		}
	} else {
		cout << "NO" << endl;
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