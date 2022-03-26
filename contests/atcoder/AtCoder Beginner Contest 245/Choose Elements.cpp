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
	ll n, k;
	cin >> n >> k;
	
	vi v1, v2;

	loop(i, 0, n) {
		int temp;
		cin >> temp;
		v1.pb(temp);
	}
	
	loop(i, 0, n) {
		int temp;
		cin >> temp;
		v2.pb(temp);
	}

	bool a_prev = true;
	bool b_prev = true;

	loop(i, 0, n-1) {
		bool a_curr = false, b_curr = false;

		if((a_prev and abs(v1[i+1] - v1[i]) <= k) or (b_prev and abs(v1[i+1] - v2[i]) <= k)) {
			a_curr = true;
		}
 		if((a_prev and abs(v2[i+1] - v1[i]) <= k) or (b_prev and abs(v2[i+1] - v2[i]) <= k)) {
			b_curr = true;
		}

		if(!a_curr and !b_curr) {
			cout << "No" << endl;
			return;
		}

		a_prev = a_curr;
		b_prev = b_curr;
	}

	cout << "Yes" << endl;
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