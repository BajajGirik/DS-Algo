class Solution {
    public int minimumLength(String s) {
      int[] charFreq = new int[27];

      for (int i=0; i<s.length(); ++i) {
        charFreq[s.charAt(i) - 'a']++;
      }

      int finalLength = 0;

      for (int i=0; i<27; ++i) {
        if (charFreq[i] == 0) {
          continue;
        }

        int isOdd = charFreq[i] & 1;
        finalLength += (isOdd == 1) ? 1 : 2;
      }

      return finalLength;
    }
}

// a a a a a a -> 6
// a a a a -> 4
// a a -> 2
//
// a a a a a a a -> 7
// a a a a a -> 5
// a a a -> 3
// a -> 1
