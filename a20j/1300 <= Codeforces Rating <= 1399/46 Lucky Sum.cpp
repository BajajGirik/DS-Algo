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

vi v;

void calcNexts() {
	v.pb(4);
	v.pb(7);
	ll mul = 10;
	ll last = 0;

	loop(i, 0, 10) {
		ll n = v.size();
		loop(j, last, n) {
			v.pb(v[j] + 4*mul);
		}
		loop(j, last, n) {
			v.pb(v[j] + 7*mul);
		}

		last = n;
		mul *= 10;
	}
}	

void solve() {
	ll l, r;
	cin >> l >> r;

	calcNexts();
	auto start = lower_bound(all(v), l);
	ll total = 0;

	loop(i, start, v.end()) {
		ll n = *i;
		if(n >= r) {
			total += (r - l + 1) * n;
			break;
		}

		total += (n - l + 1) * n;
		l = n + 1;
	}

	cout << total << endl;
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
