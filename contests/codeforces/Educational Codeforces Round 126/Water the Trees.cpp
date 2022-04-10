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
	loop(i, 0, n) {
		cin >> v[i];
	}

	sort(all(v));

	ll even1 = 0, odd1, even2 = 0, odd2, make_even, make_odd;
	odd2 = make_even = v[n-1] % 2;
	odd1 = make_odd = v[n-1] % 2 == 1 ? 0 : 1;

	loop(i, 0, n-1) {
		// odd
		even1 += (v[n-1] + make_odd - v[i]) / 2;
		odd1 += (v[n-1] + make_odd - v[i]) % 2;

		// even
		even2 += (v[n-1] + make_even - v[i]) / 2;
		odd2 += (v[n-1] + make_even - v[i]) % 2;
	}


	if(even1 > odd1) {
		ll temp = (even1 - odd1) / 3;
		even1 -= temp;
		odd1 += temp * 2;
	}

	if(even2 > odd2) {
		ll temp = (even2 - odd2) / 3;
		even2 -= temp;
		odd2 += temp * 2;
	}

	if(odd1 > even1) {
		even1 = 2*odd1 - 1;
	} else if(even1 - odd1 == 2) {
		even1 = 2*(odd1+2) - 1;
	} else {
		even1 = 2*even1;
	}
	
	if(odd2 > even2) {
		even2 = 2*odd2 - 1;
	} else if(even2 - odd2 == 2) {
		even2 = 2*(odd2 + 2) - 1;
	} else {
		even2 = 2*even2;
	}

	cout << min(even1 , even2) << endl;
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