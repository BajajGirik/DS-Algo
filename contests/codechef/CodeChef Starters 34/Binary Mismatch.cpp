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
	string s;
	cin >> s;

	if(n&1) {
		cout << "NO" << endl;
		return;
	}

	ll z = 0, o = 0, dp[n];
	unordered_map<ll, ll> m;

	loop(i, 0, n) {
		if(s[i] == '0') {
			++z;
		} else {
			++o;
		}

		m[z - o] = i;
		dp[i] = o;
	}

	ll temp = n/2 - o;
	if(m.find(temp) != m.end()) {
		cout << "YES" << endl;
		cout << 1 << " " << m[temp] + 1 << endl;
	} else {
		cout << "NO" << endl;
	}

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