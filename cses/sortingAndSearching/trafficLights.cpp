#include <iostream>
#include <map>
#include <set>
#include <utility>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  long x;
  int n;
  cin >> x >> n;

  multiset<long, greater<long>> lengths;
  set<long> s;
  s.insert(0);
  s.insert(x);

  for (int i = 0; i < n; ++i) {
    long temp;
    cin >> temp;

    auto next = s.lower_bound(temp);
    auto prev = next;
    --prev;

    auto delPtr = lengths.find(*next - *prev);
    if (delPtr != lengths.end()) {
      lengths.erase(delPtr);
    }
    lengths.insert(*next - temp);
    lengths.insert(temp - *prev);

    s.insert(temp);
    cout << *lengths.begin() << " ";
  }

  cout << "\n";
  return 0;
}
