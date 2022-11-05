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

  if (n == 0) {
    return 0;
  }

  // Better approach would be to use hashmaps
  sort(v.begin(), v.end());

  long prev = v[0];
  long count = 1;
  for (int i = 1; i < n; ++i) {
    if (prev != v[i]) {
      ++count;
      prev = v[i];
    }
  }

  cout << count << "\n";
  return 0;
}
