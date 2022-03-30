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

	vi odd, even;
	loop(i, 0, n) {
		ll temp;
		cin >> temp;

		if(temp & 1) {
			odd.pb(temp);
		} else {
			even.pb(temp);
		}
	}

	bool isOdd = odd.size() & 1;

	if(odd.size() / 2 == 0 or (isOdd and even.size() == 0)) {
		cout << "-1" << endl;
		return;
	}

	cout << odd[0] << " " << odd[1] << " ";
	
	ll end;
	if(isOdd) {
		end = odd.size() - 1;
	} else {
		end = odd.size();
	}

	loop(i, 2, end) {
		cout << odd[i] << " ";
	}

	loop(i, 0, even.size()) {
		cout << even[i] << " ";
	}

	if(isOdd) {
		cout << odd[odd.size() - 1];
	}

	cout << endl;
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