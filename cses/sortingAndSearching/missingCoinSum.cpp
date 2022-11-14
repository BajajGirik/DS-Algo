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

  long sum = 0;
  for (int i = 0; i < n; ++i) {
    if (v[i] > sum + 1) {
      cout << sum + 1 << "\n";
      return 0;
    }

    sum += v[i];
  }

  cout << sum + 1 << "\n";
  return 0;
}
