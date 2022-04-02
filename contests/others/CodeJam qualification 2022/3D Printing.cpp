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
#define TARGET			  1000000
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
	ll colors[] = {LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX};
	loop(i, 0, 3) {
		loop(j, 0, 4) {
			ll temp;
			cin >> temp;

			colors[j] = min(colors[j], temp);
		}
	}

	ll sum = 0;
	loop(i, 0, 4) {
		if(sum + colors[i] > TARGET) {
			colors[i] = TARGET - sum;
			sum = TARGET;
		} else {
			sum += colors[i];
		}
	}

	if(sum != TARGET) {
		cout << "IMPOSSIBLE" << endl;
		return;
	} 

	loop(i, 0, 4) {
		cout << colors[i] << " ";
	}

	cout << endl;
}

int main () {
	// clock_t start = clock();
	file_i_o();
	ll T=1;
	cin >> T;
	loop(i, 1, T+1) {
		cout << "Case #" << i << ": "; 
		solve();
	}
	// #ifndef ONLINE_JUDGE
	// 	clock_t end = clock();
	// 	cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
	// 	<< " sec";
	// #endif
	return 0;
}