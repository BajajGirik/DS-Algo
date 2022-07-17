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

// 


void solve() {
	// n - total number of cities
	// m - number of pairs of cities where no roads to be constructed
	int n, m;
	cin >> n >> m;


	vvi noEdges(n+1, vi {});
	loop(i, 0, m) {
		int v1, v2;
		cin >> v1 >> v2;

		noEdges[v1].pb(v2);
		noEdges[v2].pb(v1);
	}

	// this index will be like the center where most of the edges are connected
	int centerEdge;
	loop(i, 1, n+1) {
		if(noEdges[i].size() == 0) {
			centerEdge = i;
			break;
		}
	}

	cout << n-1 << endl;
	loop(i, 1, n+1) {
		if(i == centerEdge)
			continue;
		cout << centerEdge << " " << i << endl;
	}
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
