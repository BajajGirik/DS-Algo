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

char negateCh(char ch) {
	if(ch == '(')
		return ')';

	return '(';
}

bool palindrome(string s, ll start, ll end) {
	if(start == end)
		return false;

	ll j = end;
	for(ll i = start; i < j; ++i) {
		if(s[i] != s[j])
			return false;
		--j;
	}

	return true;
}

void solve() {
	ll n, count = 0, removed_index = 0;
	string s;
	char first = '(';
	cin >> n;
	cin >> s;

	stack<char> regular;

	loop(i,0,n) {
		if(!regular.empty() and first != ')' and regular.top() == negateCh(s[i])) {
			regular.pop();
		} else {
			regular.push(s[i]);
			if (regular.size() == 1)
				first = s[i];
		}

		if(regular.empty() or (i!=removed_index and s[i] == first)) {
			++count;
			removed_index = i+1;
			regular = stack<char>();
		}
	}

	cout << count << " " << n-removed_index << endl;
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
