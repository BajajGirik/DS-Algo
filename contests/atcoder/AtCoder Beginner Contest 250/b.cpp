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
	int n, a, b;
	cin >> n >> a >> b;

	string s1 = "", s2 = "";
	
	loop(i, 0, b) {
		s1 += ".";
	}

	loop(i, 0, b) {
		s2 += "#";
	}


	string r1 = "", r2 = "";
	loop(i, 0, n) {
		if(i&1) {
			r1 += s2;
			r2 += s1;
		}
		else {
			r1 += s1;
			r2 += s2;
		}
	}
	
	loop(i, 0, n) {
		string temp;
		if(i&1) {
			temp = r2;
		} else {
			temp = r1;
		}

		loop(j, 0, a) {
			cout << temp << endl;
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