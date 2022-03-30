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

void append(unordered_map<ll, vi> &m, ll key, ll value) {
	if(m.find(key) != m.end()) {
		m[key].pb(value);
	} else {
		vi temp;
		temp.pb(value);
		m[key] = temp;
	}
}

void solve() {
	ll n, m, q;
	cin >> n >> m >> q;


	unordered_map<ll, vi> edges;
	unordered_set<ll> nodes;
	unordered_set<ll> frozen_nodes;
	queue<ll> outer_nodes; 

	loop(i, 0, m) {
		ll t1, t2;
		cin >> t1 >> t2;

		nodes.insert(t1);
		nodes.insert(t2);

		append(edges, t1, t2);
		append(edges, t2, t1);
	}

	/**************** Queries ******************/
	while(q--) {
		int q1;
		ll q2;
		cin >> q1 >> q2; 

		switch(q1) {
			case 1:
				if(frozen_nodes.find(q2) == frozen_nodes.end()) {
					frozen_nodes.insert(q2);
					outer_nodes.push(q2);
				}
				break;
			case 2:
				if(frozen_nodes.size() == nodes.size())
					break;

				while(q2--) {
					ll len = outer_nodes.size();
					loop(i, 0, len) {
						for(auto edge_node: edges[outer_nodes.front()]) {
							if(frozen_nodes.find(edge_node) == frozen_nodes.end()) {
								frozen_nodes.insert(edge_node);
								outer_nodes.push(edge_node);
							}
						}
						outer_nodes.pop();
					}
				}
				break;

			case 3:
				if(frozen_nodes.find(q2) != frozen_nodes.end()) {
					cout << "YES" << endl;
				} else {
					cout << "NO" << endl;
				}
				break;
		}
	}
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