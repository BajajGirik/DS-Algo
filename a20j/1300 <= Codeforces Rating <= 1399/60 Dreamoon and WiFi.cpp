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

int factorial(int n) {
	if(n <= 1)
		return 1;

	return n * factorial(n-1);
}

void solve() {
	string s1, s2;
	cin >> s1 >> s2;

	int totalCorrectMovement = 0;

	loop(i, 0, s1.size()) {
		switch(s1[i]) {
			case '+': 
				++totalCorrectMovement;
				break;
			case '-':
				--totalCorrectMovement;
				break;
			default:
				break;
		}
	}

	int totalMovement = 0, options = 0;
	loop(i, 0, s2.size()) {
		switch(s2[i]) {
			case '+':
				++totalMovement;
				break;
			case '-':
				--totalMovement;
				break;
			case '?':
				++options;
			default:
				break;
		}
	}

	if(totalMovement + options < totalCorrectMovement || totalMovement - options > totalCorrectMovement) {
		cout << 0 << endl;
	} else if(options%2 != abs(totalCorrectMovement-totalMovement)%2) {
		cout << 0 << endl;
	} else {
		int x = abs((totalCorrectMovement-totalMovement + options)/2);
		int y = abs((options - totalCorrectMovement + totalMovement)/2);
		double ans = (double)factorial(options) / (factorial(x) * factorial(y));
		ans /= pow(2, options);
		printf("%.9f", ans);
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
