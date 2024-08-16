class Solution {
  private boolean recurse(String s, int index, long curr, long prev) {
    if (s.length() == index && prev - curr == 1) {
      return true;
    }

    if (s.length() == index) {
      return false;
    }

    if (prev != -1 && curr >= prev) {
      return false;
    }

    String currStr = String.valueOf(curr);

    if (currStr.length() > s.length() / 2 + 1) {
      return false;
    }

    String ch = String.valueOf(s.charAt(index));
    int num = Integer.parseInt(ch);

    if (prev == -1 || prev - curr == 1) {
      boolean result = recurse(s, index + 1, num, curr);
      if (result) {
        return result;
      }
    }

    long newCurr = num;
    if (curr != 0) {
      newCurr += curr * 10;
    }

    return recurse(s, index + 1, newCurr, prev);
  }

  public boolean splitString(String s) {
    return recurse(s, 0, 0, -1);
  }
}

