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

	vector<ll> v;
	bool zero_present = false;
	bool one_present = false;

	loop(i, 0, n) {
		ll temp;
		cin >> temp;
		if(temp == 0 or temp == 2)
			zero_present = true;
		if(temp == 1)
			one_present = true;

		v.pb(temp);
	}

	sort(all(v));


	if(zero_present && one_present) {
		cout << "NO" << endl;
		return;
	}

	if(zero_present or !one_present) {
		cout << "YES" << endl;
		return;
	}
	
	int j = 0;
	while(v[j] == 1) ++j;

	loop(i, j, n-1) {
		if(v[i] + 1 == v[i+1]) {
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;
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