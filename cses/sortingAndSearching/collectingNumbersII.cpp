#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<long> v(n);
  vector<long> original(n);

  for (int i = 0; i < n; ++i) {
    cin >> original[i];

    v[original[i] - 1] = i;
  }

  long total = 0;
  for (int i = 1; i < n; ++i) {
    if (v[i - 1] > v[i]) {
      ++total;
    }
  }
  ++total;

  while (m--) {
    int a, b;
    cin >> a >> b;

    --a;
    --b;
    int _a = original[a] - 1;
    int _b = original[b] - 1;

    // earlier total calcs
    int earlier = 0;
    if (_a > 0 && v[_a - 1] > v[_a] && _b != _a - 1) {
      ++earlier;
    }
    if (_a < n - 1 && v[_a] > v[_a + 1] && _b != _a + 1) {
      ++earlier;
    }
    if (_b > 0 && v[_b - 1] > v[_b]) {
      ++earlier;
    }
    if (_b < n - 1 && v[_b] > v[_b + 1]) {
      ++earlier;
    }

    // swapping
    long temp = v[_a];
    v[_a] = v[_b];
    v[_b] = temp;

    temp = original[a];
    original[a] = original[b];
    original[b] = temp;

    // later total calcs
    int later = 0;
    if (_a > 0 && v[_a - 1] > v[_a] && _b != _a - 1) {
      ++later;
    }
    if (_a < n - 1 && v[_a] > v[_a + 1] && _b != _a + 1) {
      ++later;
    }
    if (_b > 0 && v[_b - 1] > v[_b]) {
      ++later;
    }
    if (_b < n - 1 && v[_b] > v[_b + 1]) {
      ++later;
    }

    total += (later - earlier);
    cout << total << "\n";
  }
  return 0;
}
