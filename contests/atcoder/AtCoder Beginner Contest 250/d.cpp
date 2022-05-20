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

const int MAX_SIZE = 1000000;

vector<bool> isComposite(MAX_SIZE, false);
vector<ll> primes;

void SieveOfEratosthesis() {
	loop(i, 2, MAX_SIZE) {
		if(isComposite[i]) continue;
		primes.pb(i);
		for(int j = 2*i; j < MAX_SIZE; j += i) {
			isComposite[j] = true;
		}
	}
}


void solve() {
	ll n;
	cin >> n;
	SieveOfEratosthesis();

	ll size = primes.size(), res = 0, q = 0;

	loop(i, 1, size) {
		ll temp = primes[i]*primes[i]*primes[i];
		ll tempq = q;
		while(q >= 0) {
			if(temp * primes[q] <= n) {
				res += q+1;
				break;
			}
			q--;
		}

		if(q < 0) break;
		else if(tempq == q) ++q;
	}

	cout << res << endl;
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