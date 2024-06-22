import java.util.HashMap;

class Solution {
  private HashMap<String, Boolean> memo;

  private String generateKey(int i, int pCounter) {
    return i + "-" + pCounter;
  }

  private boolean recurse(String s, String p, char precedingChar, int i, int pCounter) {
    String key = generateKey(i, pCounter);

    if (this.memo.containsKey(key)) {
      return this.memo.get(key);
    }

    if (s.length() == i && p.length() == pCounter) {
      this.memo.put(key, true);
      return true;
    }

    if (p.length() == pCounter) {
      this.memo.put(key, false);
      return false;
    }

    if (s.length() == i) {
      for (int j = pCounter + 1; j < p.length(); j += 2) {
        if (p.charAt(j) != '*') {
          this.memo.put(key, false);
          return false;
        }
      }

      boolean result = p.charAt(p.length() - 1) == '*';
      this.memo.put(key, result);
      return result;
    }

    char sChar = s.charAt(i);
    char pChar = p.charAt(pCounter);

    if (pChar == '*' && (precedingChar == '.' || precedingChar == sChar)) {
      boolean result = recurse(s, p, precedingChar, i+1, pCounter + 1) || recurse(s, p, precedingChar, i+1, pCounter) || recurse(s, p, precedingChar, i, pCounter + 1);
      this.memo.put(key, result);
      return result;
    }

    if (pChar == '*') {
      boolean result = recurse(s, p, pChar, i, pCounter + 1);
      this.memo.put(key, result);
      return result;
    }

    boolean isNextCharStar = pCounter + 1 < p.length() && p.charAt(pCounter + 1) == '*';
    if (isNextCharStar) {
      boolean result = recurse(s, p, pChar, i, pCounter + 1);
      this.memo.put(key, result);
      return result;
    }

    if (pChar == '.' || pChar == sChar) {
      boolean result = recurse(s, p, pChar, i+1, pCounter + 1);
      this.memo.put(key, result);
      return result;
    }

    this.memo.put(key, false);
    return false;
  }
  
  public boolean isMatch(String s, String p) {
    this.memo = new HashMap<>();
    boolean result = recurse(s, p, p.charAt(0), 0, 0);
    this.memo = null;
    return result;
  }
}
