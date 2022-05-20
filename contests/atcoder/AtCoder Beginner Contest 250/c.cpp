/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define vi                vector<int>
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
	int n, q;
	cin >> n >> q;
	vi v(n), index(n+1);

	loop(i, 0, n) {
		v[i] = i+1;
		index[i+1] = i;
	}


	while(q--) {
		int x;
		cin >> x;
		
		if(index[x] < n-1) {
			int temp = v[index[x] + 1];
			v[index[x] + 1] = x;
			v[index[x]] = temp;

			++index[x];
			--index[temp];
		} else {
			v[index[x]] = v[index[x] - 1];
			v[index[x] - 1] = x;

			--index[x];
			++index[v[n-1]];
		}
	}

	loop(i, 0, n) {
		cout << v[i] << " ";
	}

	cout << endl;
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