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

	vi v1;
	unordered_map<ll, ll> s1, s2;

	loop(i, 0, n) {
		ll temp;
		cin >> temp;
		v1.pb(temp);
		
		if(s1.find(temp) != s1.end())
			++s1[temp];
		else
			s1[temp] = 1;
	}

	ll equal = 0;
	
	loop(i, 0, n) {
		ll temp;
		cin >> temp;
		
		if(temp == v1[i]) {
			++equal;
		}

		if(s2.find(temp) != s2.end())
			++s2[temp];
		else
			s2[temp] = 1;
	}

	ll not_equal = 0;
	for(auto x: s1) {
		if(s2.find(x.first) != s2.end()) {
			not_equal += x.second*s2[x.first];
		}
	}

	not_equal -= equal;

	cout << equal << endl << not_equal << endl;
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