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
	ll x1 = -101, x2 = -101, y1 = -101, y2 = -101;

	int X[3], Y[3];
	loop(i, 0, 3) {
		ll x, y;
		cin >> x >> y;

		X[i] = x;
		Y[i] = y;

		if(x1 == -101) {
			x1 = x;
		} else if(x2 == -101 and x1 != x) {
			x2 = x;
		}

		if(y1 == -101) {
			y1 = y;
		} else if (y2 == -101 and y != y1) {
			y2 = y;
		}
	}


	int countX = 0, countY = 0;
	loop(i, 0, 3) {
		if(X[i] == x1) {
			++countX;
		}

		if(Y[i] == y1) {
			++countY;
		}
	}

	if(countX == 2) {
		cout << x2 << " ";
	} else {
		cout << x1 << " ";
	}

	if(countY == 2) {
		cout << y2;
	} else {
		cout << y1;
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