import java.awt.List;
import java.util.ArrayList;

class Solution {
  private void recurse(ArrayList<Integer> result, int curr, int max) {
    for (int i=0; i<=9 && curr + i <= max; ++i) {
      int _curr = curr + i;
      if (_curr == 0) {
        continue;
      }
      result.add(_curr);
      if (_curr * 10 <= max) {
        recurse(result, _curr * 10, max);
      }
    }
  }

  public List<Integer> lexicalOrder(int n) {
    ArrayList<Integer> result = new ArrayList<>();
    recurse(result, 0, n);
    return result;
  }
}
