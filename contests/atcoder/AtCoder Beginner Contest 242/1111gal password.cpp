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
#define mod               998244353LL
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
	unsigned ll n;
	cin >> n;

	vi count(11);
	loop(i, 1, 9) {
		count[i]+=2;
	}
	++count[9];

	loop(i, 2, 10) {
		++count[i];
	}

	loop(i, 2, n) {
		vi a(11);
		a = count;

		a[2] = (a[2] + count[1]) % mod;
		a[8] = (a[8] + count[9]) % mod;

		loop(x, 2, 9) {
			a[x+1] = (a[x+1] + count[x]) % mod;
			a[x-1] = (a[x-1] + count[x]) % mod;
		}

		count = a;
	}

	unsigned ll ans = 0;
	loop(i, 0, 11) {
		ans = (ans + count[i]) % mod;
	}
	cout << ans << endl;
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