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
	int n, m;
	cin >> n >> m;

	char matrix[n][m];
	loop(i, 0, n) {
		loop(j, 0, m) {
			cin >> matrix[i][j];
		}
	}

	/*loop(i, 0, n) {
		loop(j, 0, m) cout << matrix[i][j];
		cout << endl;
	}*/

	int count = 0;
	loop(i, 0, n) {
		loop(j, 0, m) {
			if(matrix[i][j] == 'P') {
				if(i-1 >= 0 and matrix[i-1][j] == 'W') {
					matrix[i-1][j] = '.';
					++count;
				} else if(i+1 < n and matrix[i+1][j] == 'W') {
					matrix[i+1][j] = '.';
					++count;
				} else if(j-1 >= 0 and matrix[i][j-1] == 'W') {
					matrix[i][j-1] = '.';
					++count;
				} else if(j+1 < m and matrix[i][j+1] == 'W') {
					matrix[i][j+1] = '.';
					++count;
				}
			}
		}
	}

	cout << count << endl;
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
