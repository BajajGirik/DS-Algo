/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define vi                vector<int>
#define vvi               vector<vi>
#define all(v)            v.begin(), v.end()
#define pii               pair<int, int>
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

int countNodes(int parent, int root, vector<vector<pair<int, int>>> &edges, vector<int> &options, bool f = true) {
	int total = 1;
	rloop(i, edges[root]) {
		if(i.ff == parent) continue;
		if(f and i.ss == 1) {
			int temp = countNodes(root, i.ff, edges, options, false);
			options.pb(temp);
			total += temp;
		} else total += countNodes(root, i.ff, edges, options, f);
	}

	return total;
}

void solve() {
	int n, k;
	cin >> n >> k;

	vector<vector<pair<int, int>>> edges(n+1);
	loop(i, 0, n-1) {
		int u, v, x;
		cin >> u >> v >> x;
		edges[u].pb({v,x});
		edges[v].pb({u,x});
	}


	vector<int> options;
	countNodes(0, 1, edges, options);

	sort(all(options), greater<int>());

	int savedCities = 0, index = 0;	
	rloop(i, options) {
		if(n - savedCities <= k) break;
		savedCities += i;
		++index;

	}

	if(n-savedCities <= k) cout << index << endl;
 	else cout << -1 << endl;
}

int main () {
	clock_t start = clock();
	file_i_o();
	int T=1;
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

/*
		1
	  / | \
     2  3  6
	   / \ 
      4   5  
	 / \
    7   8
*/

/*
		1
	  /   \
     2     3
	/ \     \
   4   5     6

*/