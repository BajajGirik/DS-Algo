#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  long median = v[n / 2];

  long minCost = 0;
  for (int i = 0; i < n; ++i) {
    minCost += abs(v[i] - median);
  }

  cout << minCost << "\n";
  return 0;
}
