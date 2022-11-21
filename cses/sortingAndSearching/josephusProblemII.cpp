#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;
#define int long long
#define endl '\n'

// I'm not sure about the solution that much as well, I tried solving it on my
// own using double-circular linked list but was giving TLE. We need to use the
// find_by_order function specifically to make this work in time.
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  indexed_set s;
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    s.insert(i);

  int ind = k % n;
  while (n--) {
    auto y = s.find_by_order(ind);
    cout << *y << ' ';
    s.erase(y);
    if (n)
      ind = (ind % n + k) % n;
  }
}
