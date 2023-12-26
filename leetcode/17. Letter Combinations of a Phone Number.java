import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<String> combinations(String digits, int index, List<String> computedResults, List<String> digitToCharMapping) {
        if (index == digits.length()) {
            return computedResults;
        }

        int digit = digits.charAt(index) - '2';
        String charsOnDigit = digitToCharMapping.get(digit);

        ArrayList<String> results = new ArrayList<>();

        for (int i=0; i<charsOnDigit.length(); ++i) {
            String currChar = String.valueOf(charsOnDigit.charAt(i));

            for (int j=0; j<computedResults.size(); ++j) {
                String str = computedResults.get(j);
                results.add(str + currChar);
            }
        }

        return combinations(digits, index + 1, results, digitToCharMapping);
    }

    public List<String> letterCombinations(String digits) {
        ArrayList<String> results = new ArrayList<>();
        if (digits.length() == 0) {
            return results;
        }

        results.add("");
        ArrayList<String> digitToStringMapping = new ArrayList<>(List.of("abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"));
        return combinations(digits, 0, results, digitToStringMapping);
    }
}
