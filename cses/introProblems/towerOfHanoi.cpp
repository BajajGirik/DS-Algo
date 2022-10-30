/******************************************************/
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define all(v) v.begin(), v.end()
#define pii pair<ll, ll>
#define pb push_back
#define mp make_pair
#define mid(l, h) ((l + h) / 2)
#define loop(i, a, b) for (auto i = a; i < b; ++i)
#define looprev(i, a, b) for (auto i = a; i >= b; --i)
#define rloop(i, a) for (auto i : a)
#define rrloop(i, a) for (auto &i : a)
#define mod 1'000'000'007
#define endl '\n'
#define ff first
#define ss second
/******************************************************/

void file_i_o() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

int getDestinationToMoveSmallSet(int a, int b) {
  if (a != 1 && b != 1) {
    return 1;
  }
  if (a != 2 && b != 2) {
    return 2;
  }

  return 3;
}

vector<string> moves;

void toh(int noOfItemsToMove, int from, int to) {
  if (noOfItemsToMove == 0) {
    return;
  }

  int dest = getDestinationToMoveSmallSet(from, to);
  toh(noOfItemsToMove - 1, from, dest);
  moves.push_back(to_string(from) + " " + to_string(to) + "\n");
  toh(noOfItemsToMove - 1, dest, to);
}

int main() {
  clock_t start = clock();
  file_i_o();

  /***** Main Code ******/
  int n;
  cin >> n;
  toh(n, 1, 3);

  cout << moves.size() << "\n";
  for (int i = 0; i < moves.size(); ++i) {
    cout << moves[i];
  }

#ifndef ONLINE_JUDGE
  clock_t end = clock();
  cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
       << " sec";
#endif
  return 0;
}
