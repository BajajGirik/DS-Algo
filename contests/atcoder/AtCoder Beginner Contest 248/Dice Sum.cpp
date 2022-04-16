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
#define mod               998244353
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
	ll n, m, k;
	cin >> n >> m >> k;

	if(n > k) {
		cout << 0;
		return;
	}

	vvi dp(n+1, vi(k + 1, 0));

	dp[0][0] = 1;

	loop(i, 1, n + 1) {
		loop(j, 1, k + 1) {
			loop(k, 1, m + 1) {
				if(k > j) break;
				dp[i][j] += dp[i-1][j-k];
				dp[i][j] %= mod;
			}
		}
	}

	ll ans = 0;
	loop(i, 1, k+1) {
		ans += dp[n][i];
		ans %= mod;
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