/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(v)            v.begin(), v.end()
#define loop(i, a, b)     for (auto i = a; i < b; ++i)
#define looprev(i, a, b)  for (auto i = a; i >= b; --i)
#define rloop(i, a)       for (auto i : a)
#define rrloop(i, a)      for (auto &i : a)
#define endl              '\n'
#define ff                first
#define ss                second
/******************************************************/

map<char, vector<string>> m;
map<char, vector<char>> first;
map<char, bool> isCalc;
map<char, vector<char>> follow;

bool isTerminal(char ch) {
	if((ch >= 'a' and ch <= 'z') or ch == '(' or ch == ')' or ch == '*' or ch == '+' or ch == '#') {
		return true;
	}

	return false;
}

vector<char> firstOf(char nonTerminal) {
	if(isCalc[nonTerminal]) {
		return first[nonTerminal];
	}

	bool hasEpsilon = false;

	rloop(k, m[nonTerminal]) {
		int index = 0;
		do {
			hasEpsilon = false;
			if(!isTerminal(k[index])) {
				bool epsilon = false;
				rrloop(i, m[k[index]]) {
					vector<char> temp = firstOf(k[index]);
					first[nonTerminal].insert(first[nonTerminal].end(), temp.begin(), temp.end());
					if(temp.back() == '#') {
						epsilon = true;
					}
				}

				if(epsilon) {
					index++;
					hasEpsilon = true;
				} else {
					index = -1;
				}
			} else if(k[index] == '#') {
				hasEpsilon = true;
				index++;
			} else {
				first[nonTerminal].pb(k[index]);
				index = -1;
			}
		} while(index != -1 and index < k[index]);
	}

	set<char> ans;
	rloop(i, first[nonTerminal]) {
		ans.insert(i);
	}

	first[nonTerminal].clear();

	rloop(i, ans) {
		first[nonTerminal].pb(i);
	}

	if(hasEpsilon) {
		first[nonTerminal].pb('#');
	}

	isCalc[nonTerminal] = true;
	return first[nonTerminal];
}

bool checkIsCalc() {
	bool ans = true;
	rloop(i, isCalc) {
		ans = ans and i.ss;
	}

	return !ans;
}

void reduceFollows() {
	rrloop(i, follow) {
		set<char> temp;
		rloop(j, i.ss) {
			if(j != '#') {
				temp.insert(j);
			}
		}

		vector<char> finalRes;
		rloop(j, temp) {
			finalRes.pb(j);
		}

		i.ss = finalRes;
	}
}

void printFollows() {
	rloop(i, follow) {
		cout << "Follow(" << i.ff << ") : { ";

		rloop(j, i.ss) {
			cout << j << ", ";
		}

		cout << "}" << endl;
	}
}

int main () {
	string temp;
	char start = '!';

	while(cin >> temp) {
		string rhs = "";
		loop(i, 2, temp.size()) {
			rhs += temp[i];
		}

		m[temp[0]].pb(rhs);
		if(start == '!') {
			start = temp[0];
		}
	}

	rloop(i, m) {
		first[i.ff] = vector<char> {};
		follow[i.ff] = vector<char> {};
		isCalc[i.ff] = false;
	}

	follow[start] = vector<char> {'$'};

	rloop(i, isCalc) {
		if(!i.ss) {
			isCalc['-'] = false;
			m['-'] = vector<string> {string(1, i.ff)};
			firstOf('-');
		}
	}
	first.erase('-');
	m.erase('-');

	map<char, vector<char>> extras;

	rrloop(i, m) {
		rrloop(j, i.ss) {
			if(i.ff != j.back() and !isTerminal(j.back())) {
				extras[j.back()].pb(i.ff);
			}
			isCalc[j.back()] = false;
			looprev(k, j.size() - 1, 1) {
				if(isTerminal(j[k-1])) {
					continue;
				}

				int st = k;
				do {
					if(isTerminal(j[st])) {
						follow[j[k-1]].pb(j[st]);
					} else {
						follow[j[k-1]].insert(follow[j[k-1]].end(), all(first[j[st]]));
					}
					st++;
				} while(st < j.size() and first[j[st-1]].back() == '#');

				if(!isTerminal(j[k-1]) and follow[j[k-1]].back() == '#' and j[k-1] != i.ff) {
					extras[j[k-1]].pb(i.ff);
					isCalc[j[k-1]] = false;
				}
			}
		}
	}

	while(checkIsCalc()) {
		rrloop(i, isCalc) {
			if(!i.ss) {
				int counter = 0;
				loop(j, extras[i.ff].begin(), extras[i.ff].end()) {
					if(!isCalc[*j]) {
						++counter;
						continue;
					}

					follow[i.ff].insert(follow[i.ff].end(), all(follow[*j]));
				}

				if(counter == 0) {
					isCalc[i.ff] = true;
				}
			}
		}
	}

	reduceFollows();
	printFollows();
	return 0;
}