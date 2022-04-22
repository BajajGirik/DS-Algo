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
	ll n;
	cin >> n;
	
	int len = (int) ('l' - 'a');
	vector<vector<char>> v1(len);
	vector<vector<char>> v2(len);

	loop(i, 0, n) {
		string s;
		cin >> s;

		int fi = s[0] - 'a';
		int se = s[1] - 'a';

		v1[fi].pb(s[1]);
		v2[se].pb(s[0]);
	}

	ll total = 0;
	loop(i, 0, len) {
		ll ch_count[len] = {0}, total_temp = 0;
		
		rloop(j, v1[i]) {
			int ch_num = j - 'a';
			ch_count[ch_num]++;
			total_temp++;
		}

		rloop(j, v1[i]) {
			int ch_num = j - 'a';
			total += total_temp;
			total -= ch_count[ch_num];
			total_temp--;
			ch_count[ch_num]--;
		}
	}

	loop(i, 0, len) {
		ll ch_count[len] = {0}, total_temp = 0;
		rloop(j, v2[i]) {
			int ch_num = j - 'a';
			ch_count[ch_num]++;
			total_temp++;
		}

		rloop(j, v2[i]) {
			int ch_num = j - 'a';
			total += total_temp;
			total -= ch_count[ch_num];
			total_temp--;
			ch_count[ch_num]--;
		}
	}

	cout << total << endl;
}

int main () {
	clock_t start = clock();
	file_i_o();
	ll T=1;
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