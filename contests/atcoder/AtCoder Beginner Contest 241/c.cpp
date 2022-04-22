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

	string s[n];
	loop(i, 0, n) {
		cin >> s[i];
	}


	int dp[n] = { 0 };

	loop(i, 0, n) {
		int count = 0;

		loop(j, 0, n) {
			if(j < 6 and s[i][j] == '#') {
				++count;
			} else if(j >= 6 and s[i][j] == '#' and s[i][j-6] == '.') {
				++count;
			} else if(j >= 6 and s[i][j] == '.' and s[i][j-6] == '#') {
				--count;
			}

			if(i < 6 and s[i][j] == '#') {
				++dp[j];
			} else if(i >= 6 and s[i][j] == '#' and s[i-6][j] == '.') {
				++dp[j];
			} else if(i >=6 and s[i][j] == '.' and s[i-6][j] == '#') {
				--dp[j];
			}

			if(count >= 4 or dp[j] >= 4) {
				cout << "Yes";
				return;
			}
		}
	}

	
	loop(i, 5, n) {
		ll count = 0;

		for(ll j = 0; i-j >= 0; ++j) {
			if(j < 6 and s[j][i-j] == '#') {
				++count;
			} else if(j >= 6 and s[j][i-j] == '#' and s[j - 6][i - j + 6] == '.') {
				++count;
			} else if(j >=6 and s[j][i-j] == '.' and s[j - 6][i - j + 6] == '#') {
				--count;
			}

			if(count >= 4) {
				cout << "Yes";
				return;
			}
		}
	}

	loop(i, 1, n-5) {
		ll col = n-1;
		ll row = i;
		ll count = 0;

		loop(j, 0, 6) {
			if(s[row][col] == '#') {
				++count;
			}
			++row;
			--col;
		}

		if(count >= 4) {
			cout << "Yes";
			return;
		}

		while(row < n and col >= 0) {
			if(s[row][col] == '#' and s[row-6][col+6] == '.') {
				++count;
			} else if(s[row][col] == '.' and s[row-6][col+6] == '#') {
				--count;
			}

			if(count >= 4) {
				cout << "Yes";
				return;
			}

			++row;
			--col;
		}
	}


	loop(i, 0, n-5) {
		ll row = 0;
		ll col = i;

		ll count = 0;

		loop(j, 0, 6) {
			if(s[row][col] == '#') {
				++count;
			}
			++row;
			++col;
		}

		if(count >= 4) {
			cout << "Yes";
			return;
		}
	
		while(row < n and col < n) {
			if(s[row][col] == '#' and s[row-6][col-6] == '.') {
				++count;
			} else if(s[row][col] == '.' and s[row-6][col-6] == '#') {
				--count;
			}

			if(count >= 4) {
				cout << "Yes";
				return;
			}

			++row;
			++col;
		}
	}

	loop(i, 1, n-5) {
		ll row = i;
		ll col = 0;

		ll count = 0;

		loop(j, 0, 6) {
			if(s[row][col] == '#') {
				++count;
			}
			++row;
			++col;
		}

		if(count >= 4) {
			cout << "Yes";
			return;
		}
	
		while(row < n and col < n) {
			if(s[row][col] == '#' and s[row-6][col-6] == '.') {
				++count;
			} else if(s[row][col] == '.' and s[row-6][col-6] == '#') {
				--count;
			}

			if(count >= 4) {
				cout << "Yes";
				return;
			}

			++row;
			++col;
		}

	}

	cout << "No";
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