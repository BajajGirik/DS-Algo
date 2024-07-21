class Solution {
    public int repeatedStringMatch(String a, String b) {
      int bIndex = 0;
      int counter = 1;
      int matchStart = -1;

      while (bIndex != b.length()) {
        for (int i=0; i<a.length(); ++i) {
          if (a.charAt(i) == b.charAt(bIndex)) {
            if (bIndex == 0) {
              matchStart = i;
            }
            bIndex++;
          } else if (bIndex != 0) {
            counter = 1;
            bIndex = 0;
            i = matchStart;
          }

          if (bIndex == b.length()) {
            return counter;
          }
        }

        if (bIndex == 0) {
          break;
        }

        counter++;
      }

      return -1;
    }
}

