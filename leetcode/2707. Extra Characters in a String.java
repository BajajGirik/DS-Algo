import java.util.HashMap;
import java.util.HashSet;

class ExtraCharactersInAString {
    HashMap<String, Integer> memo;
    HashSet<String> dictionarySet;

    private String createKey(int i, String s) {
        return i + "_" + s;
    }

    private int countMinExtraChar(String s, int i, String currWord) {
        String key = this.createKey(i, currWord);
        if (this.memo.containsKey(key)) {
            return this.memo.get(key);
        }

        if (i == s.length()) {
            return currWord.length();
        }

        String newWord = currWord + s.charAt(i);
        int min = countMinExtraChar(s, i+1, newWord);

        if (this.dictionarySet.contains(newWord)) {
            min = Math.min(min, countMinExtraChar(s, i+1, ""));
        } else {
            min = Math.min(min, countMinExtraChar(s, i+1, "") + newWord.length());
        }

        this.memo.put(key, min);
        return min;
    }

    public int minExtraChar(String s, String[] dictionary) {
        this.memo = new HashMap<>();
        this.dictionarySet = new HashSet<>();

        for (int i = 0; i < dictionary.length; ++i) {
            this.dictionarySet.add(dictionary[i]);
        }

        return this.countMinExtraChar(s, 0, "");
    }
}
