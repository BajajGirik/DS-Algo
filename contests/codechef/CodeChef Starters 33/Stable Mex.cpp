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
	ll n;
	cin >> n;

	vi v(n);
	for(auto &i: v) {
		cin >> i;
	}

	sort(all(v));

	ll last = -1, i = 0;
	while(i < n) {
		while(i < n and v[i] == last) ++i;

		if(last + 1 != v[i]) {
			break;
		}

		++last;
		++i;
	}

	if(last == 0) {
		cout << -1 << endl;
		return;
	}

	if(last == -1) {
		cout << v[0] - 1 << endl;
		return;
	}

	ll count = 0, j = i;
	while(j < n) {
		ll new_last = v[j] - 1;
		ll start = new_last;
		while(j<n) {
			while(j < n and v[j] == new_last) ++j;

			if(new_last + 1 != v[j]) {
				break;
			}

			++new_last;
			++j;
		}

		if(new_last - start >= last)
			++count;
	}

	cout << count << endl;
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