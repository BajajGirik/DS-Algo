#include <climits>
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

  long currSum = 0, maxSum = LLONG_MIN;
  for (int i = 0; i < n; ++i) {
    currSum += v[i];
    if (currSum > maxSum) {
      maxSum = currSum;
    }

    if (currSum < 0) {
      currSum = 0;
    }
  }

  cout << maxSum << "\n";
  return 0;
}
