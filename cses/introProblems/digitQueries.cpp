#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void file_i_o() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

long long xpow(long long x, unsigned long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1)
      res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}

int main() {
  file_i_o();
  long long q;
  cin >> q;
  while (q--) {
    long long k;
    cin >> k;

    long long digits = 1;
    while (k - (digits * 9 * xpow(10, digits - 1)) > 0) {
      k -= digits * 9 * xpow(10, digits - 1);
      ++digits;
    }

    long long number = xpow(10, digits - 1) + (k - 1) / digits;
    string strNum = to_string(number);
    cout << strNum[(k - 1) % digits] << "\n";
  }
}
