#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  long x;
  cin >> n >> x;

  vector<long> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  int i = 0, count = 0;
  for (int j = n - 1; i <= j; --j) {
    if (v[i] + v[j] <= x) {
      ++i;
    }
    ++count;
  }

  cout << count << "\n";
  return 0;
}
