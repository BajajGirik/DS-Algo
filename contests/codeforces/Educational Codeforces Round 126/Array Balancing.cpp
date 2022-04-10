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
	ll n;
	cin >> n;

	vi a(n);
	vi b(n);


	loop(i, 0, n) {
		cin >> a[i];
	}
	
	loop(i, 0, n) {
		cin >> b[i];
	}

	ll sum = 0;
	loop(i, 0, n-1) {
		if(abs(a[i+1] - a[i]) + abs(b[i+1] - b[i]) > abs(b[i+1] - a[i]) + abs(a[i+1] - b[i])) {
			ll temp;
			temp = a[i+1];
			a[i+1] = b[i+1];
			b[i+1] = temp;
		}
		
		sum += abs(a[i+1] - a[i]) + abs(b[i+1] - b[i]);
	}

	cout << sum << endl;
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