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

ll binarySearch(vi a, ll start, ll end, ll target, bool z = false) {
	while(start <= end) {
		ll mid = (start + end) / 2;
		if(a[mid] == target) {
			return mid;
		}

		if(a[mid] > target) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	if(z) {
		return start - 1;
	}

	return start;
}


void solve() {
	ll n;
	cin >> n;

	unordered_map<ll, vi> m;
	loop(i, 0, n) {
		ll temp;
		cin >> temp;
		if(m.find(temp) != m.end()) {
			m[temp].pb(i+1);
		} else {
			m[temp] = vi {i+1}; 
		}
	}

	ll q;
	cin >> q;

	while(q--) {
		ll l, r, x;
		cin >> l >> r >> x;

		if(m.find(x) == m.end()) {
			cout << 0 << endl;
			continue;
		}

		ll size = m[x].size() - 1;
		ll start = binarySearch(m[x], 0, size, l);
		ll end = binarySearch(m[x], start, size, r, true);

		cout << (end - start + 1) << endl;
	}
}

int main () {
	clock_t start = clock();
	file_i_o();
	ll T=1;
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