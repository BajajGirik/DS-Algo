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

void printArr(vi v) {
	for(auto a: v) {
		cout << a << " ";
	}
	cout << endl;
}

ll binarySearch(vi a, ll target, ll start, ll end, bool getStartValue = true) {
	ll index = -1;

	while(start <= end) {
		ll mid = (start + end) / 2;
		if(a[mid] == target) {
			index = mid;
			if(getStartValue) {
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		} else if(a[mid] > target) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	if(index != - 1) {
		return index;
	}

	if(!getStartValue) {
		return start - 1;
	}

	return start;
}

void solve() {
	ll q;
	cin >> q;

	vi v;
	while(q--) {

		int a;
		cin >> a;


		ll x, k, index, size, j;
		switch(a) {
			case 1:
			cin >> x;

			size = v.size() - 1;
			j = -1;

			v.pb(x);
			looprev(i, size, 0) {
				if(v[i] > x) {
					swap(v[i], v[i+1]);
				} else {
					j = i;
					break;
				}
			}

			v[j + 1] = x;
			break;

			case 2:
			// find elements smaller than or equal to
			// k-th largest value

			// printArr(v);
			cin >> x >> k;
			size = v.size();

			index = binarySearch(v, x, 0, size-1, false);
			// cout << index << endl;
			if(k > index + 1) {
				cout << -1 << endl;
			} else {
				cout << v[index - k + 1] << endl;
			}
			break;

			default:
			// find elements greater than or equal to
			// k-th smallest value

			// printArr(v);
			cin >> x >> k;
			size = v.size();

			index = binarySearch(v, x, 0, size-1);
			// cout << index << endl;

			if(k > size - index) {
				cout << -1 << endl;
			} else {
				cout << v[index + k - 1] << endl;
			}
			break;
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