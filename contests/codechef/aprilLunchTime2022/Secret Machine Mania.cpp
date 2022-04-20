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

map<ll, ll> prime_factorization(ll n) {
	ll div = 2;
	map<ll, ll> res;

	while(n % div == 0) {
		n /= div;
		++res[div];
	}

	++div;
	while(div <= n) {
		if(n % div == 0) {
			n /= div;
			++res[div];
		} else {
			div += 2;
		}
	}

	return res;
}

void solve() {
	ll x, c;
	cin >> x >> c;

	map<ll, ll> prime_factors = prime_factorization(x);

	rloop(i, prime_factors) {
		ll denominator = (i.second / c) * c;
		i.second %= c;

		denominator = max(denominator, denominator + 2*i.second - c);
		if(denominator > 0) {
			x /= pow(i.first, denominator);
		}
	}

	cout << x << endl;
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