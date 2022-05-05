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
#define pinf              LLONG_MAX
#define ninf              LLONG_MIN
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

	vi v(n);
	loop(i, 0, n) {
		cin >> v[i];
	}

	sort(all(v));
	unordered_set<ll> sums;
	loop(i, 0, n-1) {
		loop(j, i + 1, n) {
			sums.insert(v[i] + v[j]);
		}
	}

	ll maxCount = 0;
	rloop(i, sums) {
		ll start = 0, end = n-1, count = 0;
		while(start < end) {
			if(v[start] + v[end] == i) {
				++count;
				++start;
				--end;
			} else if(v[start] + v[end] > i) {
				--end;
			} else {
				++start;
			}
		}
		maxCount = max(count, maxCount);
	}

	cout << maxCount << endl;
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