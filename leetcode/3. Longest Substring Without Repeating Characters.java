import java.util.HashMap;
import java.util.Map;

class Solution {
    private HashMap<Character, Integer> clearMap(HashMap<Character, Integer> s, int minValue) {
      HashMap<Character, Integer> finalHashMap = new HashMap<>();

      for (Map.Entry<Character,Integer> entry: s.entrySet()) {
        int val = entry.getValue();

        if (val > minValue) {
          finalHashMap.put(entry.getKey(), entry.getValue());
        }
      }

      return finalHashMap;
    }

    public int lengthOfLongestSubstring(String s) {
      int longestSubstringLength = 0;
      HashMap<Character, Integer> charSet = new HashMap<>();

      for (int i=0; i<s.length(); ++i) {
        char ch = s.charAt(i);

        if (charSet.containsKey(ch)) {
          longestSubstringLength = Math.max(longestSubstringLength, charSet.size());
          charSet = clearMap(charSet, charSet.get(ch));
        }

        charSet.put(ch, i);
      }

      longestSubstringLength = Math.max(longestSubstringLength, charSet.size());

      return longestSubstringLength;
    }
}
