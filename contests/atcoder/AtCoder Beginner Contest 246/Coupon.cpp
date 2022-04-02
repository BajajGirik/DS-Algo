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
	ll n, k, x;
	cin >> n >> k >> x;

	vi v;
	loop(i, 0, n) {
		ll temp;
		cin >> temp;
		v.pb(temp);
	}

	sort(all(v));

	looprev(i, n-1, 0) {
		if(v[i] < x) {
			break;
		}

		ll temp = v[i] / x;
		if(k - temp < 0) {
			v[i] -= k*x;
			k = 0;
			break;
		}


		k -= temp;
		v[i] = v[i] % x;
	}

	if(k >= n) {
		cout << 0 << endl;
		return;
	} 

	sort(all(v));
	ll sum = 0;
	loop(i, 0, n - k) {
		sum += v[i];
	}

	cout << sum << endl;

}

int main () {
	clock_t start = clock();
	file_i_o();
	ll T=1;
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