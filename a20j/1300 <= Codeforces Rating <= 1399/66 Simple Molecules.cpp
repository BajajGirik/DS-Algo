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

void initialize(int a, int b, int c, int& temp_a, int& temp_b, int& temp_c, int& bonds_12, int& bonds_23, int& bonds_31) {
	temp_a = a;
	temp_b = b;
	temp_c = c;
	bonds_12 = 0;
	bonds_23 = 0;
	bonds_31 = 0;
}

void updateTo3BondsIfNeeded(int& temp_a, int& temp_b, int& temp_c, int& bonds_12, int& bonds_23, int& bonds_31) {
	int non_zero = 0;
	if(temp_a != 0)
		non_zero = 1;
	else if(temp_b != 0)
		non_zero = 2;
	else if(temp_c != 0)
		non_zero = 3;

	bool isOdd;
	int newBonds;
	switch(non_zero) {
		case 1:
			isOdd = temp_a & 1;
			if(!isOdd && temp_a <= bonds_23) {
				newBonds = temp_a / 2;
				bonds_23 -= newBonds;
				bonds_12 += newBonds;
				bonds_31 += newBonds;
				temp_a = 0;
			}
			break;
		case 2:
			isOdd = temp_b & 1;
			if(!isOdd && temp_b <= bonds_31) {
				newBonds = temp_b / 2;
				bonds_31 -= newBonds;
				bonds_12 += newBonds;
				bonds_23 += newBonds;
				temp_b = 0;
			}
			break;
		case 3:
			isOdd = temp_c & 1;
			if(!isOdd && temp_c <= bonds_12) {
				newBonds = temp_c / 2;
				bonds_12 -= newBonds;
				bonds_23 += newBonds;
				bonds_31 += newBonds;
			}
			break;
		default:
			break;
	}
}

int getNumberOfInterConnectedAtoms(int bonds_12, int bonds_23, int bonds_31) {
	int count = 0;

	count += (bonds_12 > 0 ? 1 : 0);
	count += (bonds_23 > 0 ? 1 : 0);
	count += (bonds_31 > 0 ? 1 : 0);

	return count;
}

void formBonds(int& atom1, int &atom2, int& bonds) {
	bonds = min(atom1, atom2);
	atom1 -= bonds;
	atom2 -= bonds;
}

void solve() {
	// valence numbers of the atoms
	int a, b, c;
	cin >> a >> b >> c;

	int temp_a, temp_b, temp_c, bonds_12, bonds_23, bonds_31, count;

	// case when 1-2 start
	initialize(a, b, c, temp_a, temp_b, temp_c, bonds_12, bonds_23, bonds_31);

	formBonds(temp_a, temp_b, bonds_12);
	formBonds(temp_b, temp_c, bonds_23);
	formBonds(temp_c, temp_a, bonds_31);

	updateTo3BondsIfNeeded(temp_a, temp_b, temp_c, bonds_12, bonds_23, bonds_31);
	count = getNumberOfInterConnectedAtoms(bonds_12, bonds_23, bonds_31);

	if(temp_a == 0 && temp_b == 0 && temp_c == 0 && count >= 2) {
		cout << bonds_12 << " " << bonds_23 << " " << bonds_31 << endl;
		return;
	}

	// case when 2-3 starts
	initialize(a, b, c, temp_a, temp_b, temp_c, bonds_12, bonds_23, bonds_31);

	formBonds(temp_b, temp_c, bonds_23);
	formBonds(temp_a, temp_b, bonds_12);
	formBonds(temp_c, temp_a, bonds_31);

	updateTo3BondsIfNeeded(temp_a, temp_b, temp_c, bonds_12, bonds_23, bonds_31);
	count = getNumberOfInterConnectedAtoms(bonds_12, bonds_23, bonds_31);

	if(temp_a == 0 && temp_b == 0 && temp_c == 0 && count >= 2) {
		cout << bonds_12 << " " << bonds_23 << " " << bonds_31 << endl;
		return;
	}

	// case when 3-1 starts
	initialize(a, b, c, temp_a, temp_b, temp_c, bonds_12, bonds_23, bonds_31);

	formBonds(temp_c, temp_a, bonds_31);
	formBonds(temp_b, temp_c, bonds_23);
	formBonds(temp_a, temp_b, bonds_12);

	updateTo3BondsIfNeeded(temp_a, temp_b, temp_c, bonds_12, bonds_23, bonds_31);
	count = getNumberOfInterConnectedAtoms(bonds_12, bonds_23, bonds_31);

	if(temp_a == 0 && temp_b == 0 && temp_c == 0 && count >= 2) {
		cout << bonds_12 << " " << bonds_23 << " " << bonds_31 << endl;
		return;
	}

	cout << "Impossible" << endl;
}

int main () {
	clock_t start = clock();
	file_i_o();
	int T=1;
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
