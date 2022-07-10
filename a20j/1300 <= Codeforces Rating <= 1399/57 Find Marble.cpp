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
	// n = no. of glasses
	// s = start pos of marble
	// t = final pos of marble
	int n, s, t;
	cin >> n >> s >> t;

	// p[i] = final pos after shuffle for glass at i-th index
	// (indexing is 1 based)
	vi p(n+1);
	loop(i, 1, n+1) cin >> p[i];

	int current_pos = s;
	set<int> visited_pos;
	visited_pos.insert(s);
	int steps = 0;

	while(true) {
		if(current_pos == t) {
			break;
		}

		if(visited_pos.find(p[current_pos]) != visited_pos.end()) {
			steps = -1;
			break;
		}

		visited_pos.insert(p[current_pos]);
		++steps;

		current_pos = p[current_pos];
	}

	cout << steps << endl;
}

int main () {
	clock_t start = clock();
	file_i_o();
	int T=1;
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
