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
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt","r", stdin);
// 	freopen("output.txt","w", stdout);
// #endif
}

void solve() {
	ll r, c;
	cin >> r >> c;

	string s1="";
	loop(i, 0, c) {
		s1 += "+-";
		if(i == 0)
			cout << "..+";
		else
			cout << "-+";
	}
	s1 += "+";
	cout << endl;

	loop(i, 0, r) {
		loop(j, 0, c) {
			if(i == 0 and j == 0)
				cout << "..";
			else
				cout << "|.";
		}
		cout << "|";
		cout << endl <<  s1 << endl;
	}
}

int main () {
	// clock_t start = clock();
	file_i_o();
	ll T=1;
	cin >> T;
	loop(i, 1, T+1) {
		cout << "CASE #" << i << ":" << endl;
		solve();
	}
	// #ifndef ONLINE_JUDGE
	// 	clock_t end = clock();
	// 	cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
	// 	<< " sec";
	// #endif
	return 0;
}