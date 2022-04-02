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
#define MAXVAL			  1000000
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
	unsigned ll n;
	cin >> n;

	vector<unsigned ll> v;

	loop(i, 0, 820) {
		loop(j, i, 820) {
			unsigned ll temp = (unsigned ll) (i + j) * (i*i + j*j);
			if(temp == n) {
				cout << n << endl;
				return;
			}
			if(temp > n) {
				v.pb(temp);
				break;
			}
		}
	}

	loop(i, 1, 1000001) {
		unsigned ll temp = (unsigned ll) i * i * i;
		if(temp == n) {
			cout << n << endl;
			return;
		}
		if(temp > n) {
			v.pb(temp);
			break;
		}
	}

	sort(all(v));

	for(auto x: v) {
		if(x > n) {
			cout << x << endl;
			return;
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