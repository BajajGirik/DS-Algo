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
	vector<pair<ll, ll>> v;

	loop(i, 0, n) {
		ll x, y;
		cin >> x >> y;
		v.pb(make_pair(x,y));
	}

	string s;
	cin >> s;

	unordered_map<ll, pair<ll, ll>> m;

	loop(i, 0, n) {
		if(m.find(v[i].second) != m.end()) {
			if(s[i] == 'L') {
				m[v[i].second].first = max(m[v[i].second].first, v[i].first);
			} else {
				m[v[i].second].second = min(m[v[i].second].second, v[i].first);
			}
		} else {
			m[v[i].second].first = LLONG_MIN;
			m[v[i].second].second = LLONG_MAX;

			if(s[i] == 'L') {
				m[v[i].second].first = v[i].first;
			} else {
				m[v[i].second].second = v[i].first;
			}
		}
	}

	for(auto p: m) {
		if(p.second.first > p.second.second) {
			cout << "Yes" << endl;
			return;
		}
	}

	cout << "No" << endl;
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